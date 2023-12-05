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
    line := data[0]
    window := make(map[byte]int)
    for i := 0; i < 4; i++ {
        window[line[i]] += 1
    }
    if len(window) == 4 {
        log.Printf("answer=%d\n", 4)
        return
    }
    for i := 4; i < len(line); i++ {
        window[line[i - 4]] -= 1
        if window[line[i - 4]] == 0 {
            delete(window, line[i - 4])
        }
        window[line[i]] += 1
        // log.Printf("window size = %d, window = %v\n", len(window), window)
        if len(window) == 4 {
            log.Printf("answer=%d\n", i + 1)
            return
        }
    }
}
