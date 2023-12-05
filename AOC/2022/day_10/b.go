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

const N = 6
const M = 40

func printScreen(screen [][]byte) {
	for r := 0; r < N; r++ {
		for c := 0; c < M; c++ {
			fmt.Printf("%c", screen[r][c])
		}
		fmt.Printf("\n")
	}
}

func updateScreen(screen [][]byte, cycle, reg int) {
	row := cycle / 40
	col := cycle % 40
	var toPrint byte
	toPrint = '.'
	if reg == col || reg == col-1 || reg == col+1 {
		toPrint = '#'
	}
	screen[row][col] = toPrint
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	reg := 1
	screen := make([][]byte, N)
	for i := 0; i < N; i++ {
		screen[i] = make([]byte, M)
	}
	cycle := 0
	n := len(data)
	i := 0
	for true {
		if i == n {
			break
		}
		if data[i] == "noop" {
			updateScreen(screen, cycle, reg)
			cycle++
			i++
			continue
		}
		info := strings.Split(data[i], "addx ")
		val, err := strconv.Atoi(info[1])
		if err != nil {
			log.Fatalf("couldn't convert %v to int: %v\n", info[1], err)
			return
		}
		updateScreen(screen, cycle, reg)
		cycle++
		i++
		updateScreen(screen, cycle, reg)
		reg += val
		cycle++
	}
	printScreen(screen)
}
