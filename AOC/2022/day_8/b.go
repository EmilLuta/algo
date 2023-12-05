package main

import (
	"errors"
	"fmt"
	"log"
	"os"
    "strings"
)

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
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
    answer := 0
    for R := 0; R < n; R++ {
        for C := 0; C < n; C++ {
            me := grid[R][C]
            canSee := 0
            curr := 1
            // up
            for r := R - 1; r >= 0; r-- {
                canSee++
                if me <= grid[r][C] {
                    break
                }
            }
            curr *= canSee
            // down
            canSee = 0
            for r := R + 1; r < n; r++ {
                canSee++
                if me <= grid[r][C] {
                    break
                }
            }
            curr *= canSee
            // left
            canSee = 0
            for c := C - 1; c >= 0; c-- {
                canSee++
                if me <= grid[R][c] {
                    break
                }
            }
            curr *= canSee
            // right
            canSee = 0
            for c := C + 1; c < n; c++ {
                canSee++
                if me <= grid[R][c] {
                    break
                }
            }
            curr *= canSee
            answer = max(answer, curr)
        }
    }
    log.Printf("answer=%d\n", answer)
}
