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

func isLetter(c byte) bool {
	return 'A' <= c && c <= 'Z'
}

func getMove(move string) (int, int, int) {
	move = move[5:]
    data := strings.Split(move, " from ")
    count, err := strconv.Atoi(data[0])
    if err != nil {
        log.Fatalf("couldn't convert value %v to int: %v\n", data[0], err)
        panic("fail")
    }
    data = strings.Split(data[1], " to ")
    from, err := strconv.Atoi(data[0])
    if err != nil {
        log.Fatalf("couldn't convert value %v to int: %v\n", data[0], err)
        panic("fail")
    }
    to, err := strconv.Atoi(data[1])
    if err != nil {
        log.Fatalf("couldn't convert value %v to int: %v\n", data[1], err)
        panic("fail")
    }
    return count, from - 1, to - 1
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	if len(data) == 0 {
		log.Fatalf("empty file\n")
		return
	}
	n := (len(data[0]) + 1) / 4
	stacks := make([][]byte, n)
	for i := range stacks {
		stacks[i] = make([]byte, 0)
	}
	for _, line := range data {
		if line == "" {
			continue
		}
		if strings.HasPrefix(line, " 1") {
			for i := range stacks {
				l := len(stacks[i])
				for j := 0; j < l/2; j++ {
					stacks[i][j], stacks[i][l-j-1] = stacks[i][l-j-1], stacks[i][j]
				}
			}
			continue
		}
		if strings.HasPrefix(line, "move") {
			count, from, to := getMove(line)
            stacks[to] = append(stacks[to], stacks[from][len(stacks[from]) - count:]...)
            stacks[from] = stacks[from][:len(stacks[from]) - count]
			continue
		}
		for i := 1; i < len(line); i += 4 {
			if isLetter(line[i]) {
				index := i / 4
				stacks[index] = append(stacks[index], line[i])
			}
		}
	}
	for i := range stacks {
        fmt.Printf("%c", stacks[i][len(stacks[i]) - 1])
	}
    fmt.Printf("\n")

}
