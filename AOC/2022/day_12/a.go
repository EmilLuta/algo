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

type pair struct {
    first int
    second int
}

func isInside(r, c, n, m int) bool {
    return 0 <= r && r < n && 0 <= c && c < m
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
	data, err := getFileData()
    if err != nil {
        log.Fatalf("couldn't read input: %v\n", err)
        return
    }
    n := len(data)
    m := len(data[0])
    grid := make([][]byte, n)
    seen := make([][]bool, n)
    count := make([][]int, n)
    for i := 0; i < n; i++ {
        grid[i] = make([]byte, m)
        seen[i] = make([]bool, m)
        count[i] = make([]int, m)
    }
    queue := make([]pair, 0)
    er := 0
    ec := 0
    for r := 0; r < n; r++ {
        for c := 0; c < m; c++ {
            grid[r][c] = data[r][c]
            seen[r][c] = false
            count[r][c] = 0
            if data[r][c] == 'S' {
                grid[r][c] = 'a'
                queue = append(queue, pair{r, c})
            }
            if data[r][c] == 'E' {
                grid[r][c] = 'z'
                er = r
                ec = c
            }
        }
    }
    index := 0
    dirs := []pair{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
    for index < len(queue) {
        p := queue[index]
        index++
        r := p.first
        c := p.second
        if seen[r][c] {
            continue
        }
        seen[r][c] = true
        for _, d := range dirs {
            nr := r + d.first
            nc := c + d.second
            if isInside(nr, nc, n, m) && !seen[nr][nc] && grid[r][c] + 1 >= grid[nr][nc] {
                queue = append(queue, pair{nr, nc})
                count[nr][nc] = max(count[nr][nc], count[r][c] + 1)
                if nr == er && nc == ec {
                    log.Printf("answer=%d\n", count[nr][nc])
                    return
                }
            }
        }
    }
}
