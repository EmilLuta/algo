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
	return strings.Split(string(file_data), "\n"), nil

}

func getDuplicate(line1, line2, line3 string) (rune, error) {
    first_set := make(map[rune]bool)
    second_set := make(map[rune]bool)
    for _, c := range line1 {
        first_set[c] = true
    }
    for _, c := range line2 {
        second_set[c] = true
    }
    for _, c := range line3 {
        _, exists_first := first_set[c]
        _, exists_second := second_set[c]
        if exists_first && exists_second {
            return c, nil
        }
    }
    return '-', errors.New("duplicate doesn't exist in the 2 compartments")
}

func getMapping() map[rune]int {
    mapping := make(map[rune]int)
    chr := 'a'
    for i := 1; i <= 26; i++ {
        mapping[chr] = i
        chr++
    }
    chr = 'A'
    for i := 27; i <= 52; i++ {
        mapping[chr] = i
        chr++
    }
    return mapping
}

func main() {
	data, err := getFileData()
    if err != nil {
        log.Fatalf("couldn't read input: %v\n", err)
        return
    }
    mapping := getMapping()
    answer := 0
    for i := 0; i < len(data) - 1; i += 3 {
        dup, err := getDuplicate(data[i], data[i + 1], data[i + 2])
        if err != nil {
            log.Fatalf("err on get duplicate: %v\n", err)
            return
        }
        answer += mapping[dup]
    }
    log.Printf("answer=%d\n", answer)
}
