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

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	rh := 0
	ch := 0
	rt := 0
	ct := 0
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
				rh -= 1
				if abs(rh-rt) > 1 {
					rt--
					if ch < ct {
						ct--
					} else if ch > ct {
						ct++
					}
				}
                if _, ok := seen[rt]; !ok {
                    seen[rt] = make(map[int]bool)
                }
                seen[rt][ct] = true
			}
		case 'D':
            for i := 0; i < count; i++ {
				rh += 1
				if abs(rh-rt) > 1 {
					rt++
					if ch < ct {
						ct--
					} else if ch > ct {
						ct++
					}
				}
                if _, ok := seen[rt]; !ok {
                    seen[rt] = make(map[int]bool)
                }
                seen[rt][ct] = true
			}
		case 'L':
            for i := 0; i < count; i++ {
				ch -= 1
				if abs(ch-ct) > 1 {
					ct--
					if rh < rt {
						rt--
					} else if rh > rt {
						rt++
					}
				}
                if _, ok := seen[rt]; !ok {
                    seen[rt] = make(map[int]bool)
                }
                seen[rt][ct] = true
			}
		case 'R':
            for i := 0; i < count; i++ {
				ch += 1
				if abs(ch-ct) > 1 {
					ct++
					if rh < rt {
						rt--
					} else if rh > rt {
						rt++
					}
				}
                if _, ok := seen[rt]; !ok {
                    seen[rt] = make(map[int]bool)
                }
                seen[rt][ct] = true
			}
		}
	}
    answer := 0
    seen[0][0] = true
    for r := range seen {
        answer += len(seen[r])
    }
    log.Printf("answer=%d\n", answer)
}
