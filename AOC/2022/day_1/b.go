package main

import (
	"log"
	"os"
	"sort"
	"strconv"
	"strings"
)

func get_elfs_data(data []byte) ([]int, error) {
	elfs := []int{}
	elfs_data := strings.Split(string(data), "\n")
	buffer := 0
	for _, val := range elfs_data {
		if val == "" {
			elfs = append(elfs, buffer)
			buffer = 0
			continue
		}

        food, err := strconv.Atoi(val)
        if err != nil {
            return []int{}, err
        }
		buffer += food
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
    // sort(elfs)
    sort.Slice(elfs, func(i, j int) bool {
        return elfs[i] < elfs[j]
    })
    n := len(elfs)
	log.Printf("answer=%d\n", elfs[n - 1] + elfs[n - 2] + elfs[n - 3])
}
