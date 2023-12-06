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

func main() {
	data, err := getFileData()
    if err != nil {
        log.Fatalf("couldn't read input: %v\n", err)
        return
    }
    answer := 0
    n := len(data)
    for _, line := range data[:n - 1] {
        elf := line[0]
        me := line[2]
        switch me {
        case 'X':
            answer += 1
            switch elf {
            case 'A':
                answer += 3
            case 'B':
                continue
            case 'C':
                answer += 6
            default:
                log.Fatalf("unexpected choice for elf: %v, expecting one of ('A', 'B', 'C')\n", elf)
                return
            }
        case 'Y':
            answer += 2
            switch elf {
            case 'A':
                answer += 6
            case 'B':
                answer += 3
            case 'C':
                continue
            default:
                log.Fatalf("unexpected choice for elf: %v, expecting one of ('A', 'B', 'C')\n", elf)
                return
            }
        case 'Z':
            answer += 3
            switch elf {
            case 'A':
                continue
            case 'B':
                answer += 6
            case 'C':
                answer += 3
            default:
                log.Fatalf("unexpected choice for elf: %v, expecting one of ('A', 'B', 'C')\n", elf)
                return
            }
        default:
            log.Fatalf("unexpected choice for me: %v, expecting one of ('X', 'Y', 'Z')\n", me)
            return
            
        }
    }
    log.Printf("answer=%d\n", answer)
}