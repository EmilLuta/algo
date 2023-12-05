package main

import (
	"errors"
	"fmt"
	"log"
	"os"
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

func main() {
	data, err := getFileData()
    if err != nil {
        log.Fatalf("couldn't read input: %v\n", err)
        return
    }
    n := len(data)
    grid := make([][]int, n, n)
    for i := 0; i < n; i++ {
        grid[i] = make([]int, n, n)
    }
    for r := 0; r < n; r++ {
        for c := 0; c < n; c++ {
            grid[r][c] = int(data[r][c] - '0')
        }
    }
    visible := 0
    for R := 0; R < n; R++ {
        for C := 0; C < n; C++ {
            bigger := true
            me := grid[R][C]
            // up
            for r := R - 1; r >= 0; r-- {
                if me <= grid[r][C] {
                    bigger = false
                }
            }
            if bigger {
                visible++
                continue
            }
            // down
            bigger = true
            for r := R + 1; r < n; r++ {
                if me <= grid[r][C] {
                    bigger = false
                }
            }
            if bigger {
                visible++
                continue
            }
            // left
            bigger = true
            for c := C - 1; c >= 0; c-- {
                if me <= grid[R][c] {
                    bigger = false
                }
            }
            if bigger {
                visible++
                continue
            }
            // right
            bigger = true
            for c := C + 1; c < n; c++ {
                if me <= grid[R][c] {
                    bigger = false
                }
            }
            if bigger {
                visible++
                continue
            }
        }
    }
    log.Printf("answer=%d\n", visible)
}
