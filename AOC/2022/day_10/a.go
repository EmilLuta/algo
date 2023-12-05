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

func getSignal(cycle, reg int, toCheck map[int]bool) int {
    if cycle % 2 == 1 {
        cycle++
    }
    if _, ok := toCheck[cycle]; ok {
        delete(toCheck, cycle)
        return cycle * reg
    }
    return 0
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	reg := 1
	toCheck := map[int]bool{20: true, 60: true, 100: true, 140: true, 180: true, 220: true}
	cycle := 1
	n := len(data)
	i := 0
	answer := 0
	for cycle <= 225 {
		// log.Printf("--- %v -- cycle = %d, reg = %d\n", data[i], cycle, reg)
		if i == n {
			break
		}
		if data[i] == "noop" {
			cycle++
			i++
			answer += getSignal(cycle, reg, toCheck)
			continue
		}
		info := strings.Split(data[i], "addx ")
		val, err := strconv.Atoi(info[1])
		if err != nil {
			log.Fatalf("couldn't convert %v to int: %v\n", info[1], err)
			return
		}
		cycle += 2
		i++
		reg += val
		answer += getSignal(cycle, reg, toCheck)
	}
	log.Printf("answer=%d\n", answer)
}
