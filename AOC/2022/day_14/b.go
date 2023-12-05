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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Point struct {
	c, r int
}

func GetPoints(line string) ([]Point, error) {
	pointsData := strings.Split(line, " -> ")
	points := make([]Point, len(pointsData))
	for i, p := range pointsData {
		point := strings.Split(p, ",")
		c, err := strconv.Atoi(point[0])
		if err != nil {
			return nil, errors.New(fmt.Sprintf("unable to get column from %v: %v", point[0], err))
		}
		r, err := strconv.Atoi(point[1])
		if err != nil {
			return nil, errors.New(fmt.Sprintf("unable to get row from %v: %v", point[1], err))
		}
		points[i] = Point{c, r}
	}
	return points, nil
}

func PrintState(grid map[int]map[int]byte, minR, maxR, minC, maxC int) {
	for r := minR; r <= maxR; r++ {
		for c := minC; c <= maxC; c++ {
			if val, ok := grid[r][c]; ok {
				fmt.Printf("%c", val)
			} else {
				fmt.Printf(".")
			}
		}
		fmt.Printf("\n")
	}
}

type State uint8

const (
	Ok State = iota
	Settled
	Flowing
)

func drip(grid map[int]map[int]byte, sand Point) bool {
	sr := sand.r
	sc := sand.c
	for true {
		positions := []Point{{sand.c, sand.r + 1}, {sand.c - 1, sand.r + 1}, {sand.c + 1, sand.r + 1}}
		dripped := false
		for _, pos := range positions {
			if _, ok := grid[pos.r][pos.c]; !ok {
				sand = pos
				dripped = true
				break
			}
		}
		if !dripped {
			if _, ok := grid[sand.r]; !ok {
				grid[sand.r] = make(map[int]byte)
			}
			grid[sand.r][sand.c] = 'o'
			if sand.r == sr && sand.c == sc {
				return false
			}
			return true
		}
	}
	log.Fatalf("this shouldn't ever be reached\n")
	return true
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	grid := make(map[int]map[int]byte)
	startR := 0
	startC := 500
	maxR, maxC, minR, minC := startR, startC, startR, startC
	grid[0] = make(map[int]byte)
	grid[startR][startC] = '+'
	for _, line := range data {
		points, err := GetPoints(line)
		if err != nil {
			log.Fatalf("couldn't parse points: %v\n", err)
			return
		}
		for i := 0; i < len(points)-1; i++ {
			p1 := points[i]
			p2 := points[i+1]
			maxR = max(maxR, max(p1.r, p2.r))
			maxC = max(maxC, max(p1.c, p2.r))
			minR = min(minR, min(p1.r, p2.r))
			minC = min(minC, min(p1.c, p2.c))
			if p1.r == p2.r {
				r := p1.r
				sc := min(p1.c, p2.c)
				ec := max(p1.c, p2.c)
				for c := sc; c <= ec; c++ {
					if _, ok := grid[r]; !ok {
						grid[r] = make(map[int]byte)
					}
					grid[r][c] = '#'
				}
			} else if p1.c == p2.c {
				c := p1.c
				sr := min(p1.r, p2.r)
				er := max(p1.r, p2.r)
				for r := sr; r <= er; r++ {
					if _, ok := grid[r]; !ok {
						grid[r] = make(map[int]byte)
					}
					grid[r][c] = '#'
				}
			} else {
				log.Fatalf("not really dealing with diagonally stuff\n")
			}
		}

	}
	maxR += 2
    minC = min(minC, startC - (maxR - minR + 1))
    maxC = max(maxC, startC + (maxR - minR + 1))
	for c := minC; c <= maxC; c++ {
		r := maxR
		if _, ok := grid[r]; !ok {
			grid[r] = make(map[int]byte)
		}
		grid[r][c] = '#'
	}
	fmt.Printf("limits r from (%d to %d) and c from (%d to %d)\n", minR, maxR, minC, maxC)
	answer := 0
	for true {
		sand := Point{startC, startR}
		if drip(grid, sand) {
			answer++
		} else {
            answer++
			break
		}
	}
	PrintState(grid, minR, maxR, minC, maxC)
	log.Printf("answer=%d\n", answer)
}
