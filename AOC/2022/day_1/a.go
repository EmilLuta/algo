package main

import (
	"log"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Elf struct {
	food []int
}

func (e *Elf) food_cal() int {
	s := 0
	for _, f := range e.food {
		s += f
	}
	return s
}

func get_elfs_data(data []byte) ([]Elf, error) {
	elfs := []Elf{}
	elfs_data := strings.Split(string(data), "\n")
	buffer := []int{}
	for _, val := range elfs_data {
		if val == "" {
			elfs = append(elfs, Elf{food: buffer})
			buffer = []int{}
			continue
		}

        food, err := strconv.Atoi(val)
        if err != nil {
            return []Elf{}, err
        }
		buffer = append(buffer, food)
	}
	return elfs, nil
}

func main() {
	args := os.Args
	if len(args) != 2 {
		log.Printf("usage: ./bin <filename>")
		return
	}
	file_data, err := os.ReadFile(args[1])
	if err != nil {
		log.Fatalf("cannot open file %v: %v\n", args[1], err)
		return
	}
	elfs, err := get_elfs_data(file_data)
    if err != nil {
        log.Fatalf("couldn't convert input file to elfs: %v\n", err)
        return
    }
	answer := 0
	for _, elf := range elfs {
		answer = max(answer, elf.food_cal())
	}
	log.Printf("answer=%d\n", answer)
}
