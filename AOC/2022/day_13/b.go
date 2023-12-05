package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"sort"
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Node struct {
	val  int
	list []*Node
}

func (n *Node) String() string {
	if n.val != -1 {
		return strconv.Itoa(n.val)
	}
	var builder strings.Builder
	builder.WriteRune('[')
	for i, child := range n.list {
		builder.WriteString(child.String())
		if i != len(n.list)-1 {
			builder.WriteRune(',')
		}
	}
	builder.WriteRune(']')
	return builder.String()
}

func (n *Node) getSentinel() *Node {
	return &Node{-1, []*Node{{n.val, make([]*Node, 0)}}}
}

type State uint8

const (
	Less State = iota
	Equal
	More
)

func (s State) String() string {
	if s == Less {
		return "less"
	}
	if s == Equal {
		return "equal"
	}
	return "more"
}

func (me *Node) Compare(other *Node) State {
	if me.val != -1 && other.val != -1 {
		if me.val < other.val {
			return Less
		}
		if me.val > other.val {
			return More
		}
		return Equal
	}
	if me.val == -1 && other.val != -1 {
		sentinelNode := other.getSentinel()
		return me.Compare(sentinelNode)

	}
	if me.val != -1 && other.val == -1 {
		sentinelNode := me.getSentinel()
		return sentinelNode.Compare(other)
	}
	n := min(len(me.list), len(other.list))
	for i := 0; i < n; i++ {
		comp := me.list[i].Compare(other.list[i])
		if comp == Less {
			return Less
		}
		if comp == More {
			return More
		}
	}
	if len(me.list) < len(other.list) {
		return Less
	}
	if len(me.list) > len(other.list) {
		return More
	}
	return Equal
}

func NewNode(data string, level int) (*Node, error) {
	n := &Node{}
	if strings.HasPrefix(data, "[") {
		if !strings.HasSuffix(data, "]") {
			return nil, errors.New("couldn't convert node list: doesn't start with [ and end with ]")
		}
		n.val = -1
		nodesData := data[1 : len(data)-1]
		p := 0
		var buffer strings.Builder
		for _, c := range nodesData {
			if c == '[' {
				p++
			} else if c == ']' {
				p--
			} else if c == ',' {
				if p == 0 {
					newNode, err := NewNode(buffer.String(), level+1)
					if err != nil {
						return nil, errors.New(fmt.Sprintf("couldn't convert new node: %v", err))
					}
					n.list = append(n.list, newNode)
					buffer.Reset()
					continue
				}
			}
			buffer.WriteRune(c)
		}
		if buffer.Len() != 0 {
			newNode, err := NewNode(buffer.String(), level+1)
			if err != nil {
				return nil, errors.New(fmt.Sprintf("couldn't convert new node: %v", err))
			}
			n.list = append(n.list, newNode)
		}
		return n, nil
	}
	val, err := strconv.Atoi(data)
	if err != nil {
		return nil, errors.New(fmt.Sprintf("couldn't convert node value: %v", err))
	}
	n.val = val
	return n, nil
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	n := len(data)
    nodes := make([]*Node, 0)
	for i := 0; i < n; i += 3 {
		left, err := NewNode(data[i], 0)
		if err != nil {
			log.Fatalf("couldn't convert left node: %v\n", err)
			return
		}
		right, err := NewNode(data[i+1], 0)
		if err != nil {
			log.Fatalf("couldn't convert left node: %v\n", err)
			return
		}
        nodes = append(nodes, left)
        nodes = append(nodes, right)
	}
    sort.Slice(nodes, func(i, j int) bool {
        return nodes[i].Compare(nodes[j]) == Less
    })
    answer := 1
    for i, node := range nodes {
        if node.String() == "[[2]]" || node.String() == "[[6]]" {
            answer *= i + 1
        }
    }
	log.Printf("answer=%d\n", answer)
}
