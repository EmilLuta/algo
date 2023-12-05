package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func getFileData() ([]string, error) {
	args := os.Args
	if len(args) != 2 {
		return nil, errors.New(fmt.Sprintf("invalid amount of parameters: %d, usage ./bin <filename>", len(args)))
	}
	file_data, err := os.ReadFile(args[1])
	if err != nil {
		return nil, errors.New(fmt.Sprintf("cannot open file %v: %v\n", args[1], err))
	}
	data := strings.Split(string(file_data), "\n")
	n := len(data)
	return data[:n-1], nil

}

type node struct {
	children map[string]*node
	size     int
	isDir    bool
	name     string
	parent   *node
}

func (n *node) IsDir() bool {
	return n.isDir
}

func (n *node) print(prefix string) {
	var data string
	if n.IsDir() {
		data = n.name + fmt.Sprintf(" (dir, size=%v)", n.size)
	} else {
		data = n.name + fmt.Sprintf(" (file, size=%d)", n.size)
	}
	fmt.Printf("%v%v\n", prefix, data)
	for _, val := range n.children {
		val.print(prefix + "\t")
	}
}

func (n *node) Print() {
	n.print("")
}

func (n *node) LoadSize() {
    if !n.isDir {
        return
    }
    n.size = 0
    for _, child := range n.children {
        child.LoadSize()
        n.size += child.size
    }
}

func (n *node) SumSmallSize() int {
    max := 100000
    if !n.IsDir() {
        return 0
    }
    sum := 0
    if n.size <= max {
        sum += n.size
    }
    for _, child := range n.children {
        sum += child.SumSmallSize()
    }
    return sum
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	root := node{children: make(map[string]*node), size: 0, isDir: true, name: "/", parent: nil}
	currNode := &root
	for _, line := range data[1:] {
		if strings.HasPrefix(line, "$") {
			if strings.HasPrefix(line, "$ cd") {
				cdData := strings.Split(line, "$ cd ")
				dir := cdData[1]
				if dir == ".." {
					currNode = currNode.parent
					continue
				}
				val, ok := currNode.children[dir]
				if !ok {
					log.Fatalf("invalid dir %v\n", dir)
					return
				}
				if !val.IsDir() {
					log.Fatalf("cannot cd in file %v\n", dir)
					return
				}
				currNode = val
			}
			continue
		}
		if strings.HasPrefix(line, "dir") {
			dirData := strings.Split(line, "dir ")
			dir := dirData[1]
			childNode := node{children: make(map[string]*node), size: 0, isDir: true, name: dir, parent: currNode}
			currNode.children[childNode.name] = &childNode
			continue
		}
		fileData := strings.Split(line, " ")
		size, err := strconv.Atoi(fileData[0])
		if err != nil {
			log.Fatalf("couldn't convert file size to int %v\n", fileData[0])
			return
		}
		file := fileData[1]
		currNode.children[file] = &node{children: nil, size: size, isDir: false, name: file, parent: currNode}
	}
    root.LoadSize()
    log.Printf("answer=%d\n", root.SumSmallSize())
}
