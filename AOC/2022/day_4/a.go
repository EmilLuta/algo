package main

import (
	"errors"
	"fmt"
	"log"
	"os"
    "strings"
    "strconv"
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
    answer := 0
    for _, line := range data {
        each := strings.Split(line, ",")
        left := strings.Split(each[0], "-")
        right := strings.Split(each[1], "-")
        left_start, err := strconv.Atoi(left[0])
        if err != nil {
            log.Fatalf("couldn't parse left_start: %v\n", err)
            return
        }
        left_end, err := strconv.Atoi(left[1])
        if err != nil {
            log.Fatalf("couldn't parse left_end: %v\n", err)
            return
        }
        right_start, err := strconv.Atoi(right[0])
        if err != nil {
            log.Fatalf("couldn't parse right_start: %v\n", err)
            return
        }
        right_end, err := strconv.Atoi(right[1])
        if err != nil {
            log.Fatalf("couldn't parse right_end: %v\n", err)
            return
        }
        if (right_start <= left_start && left_end <= right_end) || (left_start <= right_start && right_end <= left_end) {
            answer += 1
        }
    }
    log.Printf("answer=%d\n", answer)
}
