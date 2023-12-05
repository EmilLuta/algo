package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

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

func update(row, col []int, seen map[int]map[int]bool, i, j int) {
	rh := row[i]
	ch := col[i]
	rt := row[j]
	ct := col[j]
	if abs(rh-rt) > 1 {
		if rh > rt {
			rt++
		} else {
			rt--
		}
		if ch < ct {
			ct--
		} else if ch > ct {
			ct++
		}
	}
	if abs(ch-ct) > 1 {
		if ch > ct {
			ct++
		} else {
			ct--
		}
		if rh < rt {
			rt--
		} else if rh > rt {
			rt++
		}
	}
	row[j] = rt
	col[j] = ct
	if j == 9 {
		if _, ok := seen[rt]; !ok {
			seen[rt] = make(map[int]bool)
		}
		seen[rt][ct] = true
	}
}

func printState(row, col []int) {
	fmt.Printf("state: [\n")
	for i := 0; i < 10; i++ {
		fmt.Printf("\t(%d %d)\n", row[i], col[i])
	}
	fmt.Printf("]\n")
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	row := make([]int, 10)
	col := make([]int, 10)
	seen := make(map[int]map[int]bool)
	for _, line := range data {
		lineData := strings.Split(line, " ")
		direction := lineData[0][0]
		count, err := strconv.Atoi(lineData[1])
		if err != nil {
			log.Fatalf("couldn't convert %v to int\n", lineData[1])
			return
		}
		switch direction {
		case 'U':
			for i := 0; i < count; i++ {
				row[0] -= 1
				for j := 0; j < 9; j++ {
					update(row, col, seen, j, j+1)
				}
			}
		case 'D':
			for i := 0; i < count; i++ {
				row[0] += 1
				for j := 0; j < 9; j++ {
					update(row, col, seen, j, j+1)
				}
			}
		case 'L':
			for i := 0; i < count; i++ {
				col[0] -= 1
				for j := 0; j < 9; j++ {
					update(row, col, seen, j, j+1)
				}
			}
		case 'R':
			for i := 0; i < count; i++ {
				col[0] += 1
				for j := 0; j < 9; j++ {
					update(row, col, seen, j, j+1)
				}
			}
		}
                printState(row, col)
	}
	answer := 0
	for r := range seen {
		answer += len(seen[r])
	}
	log.Printf("answer=%d\n", answer)
}
