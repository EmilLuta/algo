package main

import (
	"errors"
	"fmt"
	"log"
	"os"
    "math"
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

func MinSelf(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func MaxSelf(a *int, b int) {
	if *a < b {
		*a = b
	}
}

type Point struct {
	r int
	c int
}

type Sensor struct {
	pos    Point
	beacon Point
}

type Range struct {
	start int
	end   int
}

func DistR(p1, p2 Point) int {
	d := p1.r - p2.r
	if d < 0 {
		return d * -1
	}
	return d
}

func Abs(a int) int {
	if a < 0 {
		return a * -1
	}
	return a
}

func Overlap(r1, r2 Range) bool {
	return !(r1.end < r2.start || r2.end < r1.start)
}

func DistC(p1, p2 Point) int {
	return Abs(p1.c - p2.c)
}

func getPoint(line string) (Point, error) {
	split := strings.Split(line, ", ")
	c, err := strconv.Atoi(split[0][2:])
	if err != nil {
		return Point{}, errors.New(fmt.Sprintf("failed to convert c: %v", err))
	}
	r, err := strconv.Atoi(split[1][2:])
	if err != nil {
		return Point{}, errors.New(fmt.Sprintf("failed to convert r: %v", err))
	}
	return Point{r, c}, nil
}

func PrintState(grid map[int]map[int]byte, minR, maxR, minC, maxC int) {
	for r := minR; r <= maxR; r++ {
		for c := minC; c <= maxC; c++ {
			if _, ok := grid[r]; ok {
				if val, ook := grid[r][c]; ook {
					fmt.Printf("%c", val)
				} else {
					fmt.Printf(".")
				}
			} else {
				fmt.Printf(".")
			}
		}
		fmt.Printf("\n")
	}
}

func NewSensor(line string) (Sensor, error) {
	split := strings.Split(line, ": closest beacon is at ")
	sensorPoint, err := getPoint(split[0][10:])
	if err != nil {
		return Sensor{}, errors.New(fmt.Sprintf("failed to convert sensor point: %v", err))
	}
	beaconPoint, err := getPoint(split[1])
	if err != nil {
		return Sensor{}, errors.New(fmt.Sprintf("failed to convert beacon point: %v", err))
	}
	return Sensor{sensorPoint, beaconPoint}, nil
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	sensors := make([]Sensor, len(data))
	toRemove := make(map[int]bool)
	rToCheck := 10
	for i, line := range data {
		sensor, err := NewSensor(line)
		if err != nil {
			log.Fatalf("failed to create sensor: %v\n", err)
			return
		}
		sensors[i] = sensor
		if sensor.pos.r == rToCheck {
			fmt.Printf("got sensor = %v\n", sensor.pos)
			toRemove[sensor.pos.c] = true
		}
		if sensor.beacon.r == rToCheck {
			fmt.Printf("got beacon = %v\n", sensor.beacon)
			toRemove[sensor.beacon.c] = true
		}
	}
	// ranges := make([]Range, 0)
	// for _, sensor := range sensors {
	// 	dr := DistR(sensor.pos, sensor.beacon)
	// 	dc := DistC(sensor.pos, sensor.beacon)
	// 	d := dr + dc
	// 	down := sensor.pos.r + d
	// 	up := sensor.pos.r - d
	// 	// fmt.Printf("sensor=(%d,%d) beacon=(%d,%d) dist_beacon=(%d,%d) overall_dist=%d up=%d down=%d ", sensor.pos.r, sensor.pos.c, sensor.beacon.r, sensor.beacon.c, dr, dc, d, up, down)
	// 	if sensor.pos.r == rToCheck {
	// 		ranges = append(ranges, Range{sensor.pos.c - (sensor.pos.r - d), sensor.pos.c + (sensor.pos.r + d)})
	// 		// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - (sensor.pos.r - d), sensor.pos.c + (sensor.pos.r + d))
	// 	} else if up <= rToCheck && sensor.pos.r > rToCheck {
	// 		diff := rToCheck - up
	// 		perSide := diff
	// 		ranges = append(ranges, Range{sensor.pos.c - perSide, sensor.pos.c + perSide})
	// 		// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - perSide, sensor.pos.c + perSide)
	// 	} else if down >= rToCheck && sensor.pos.r < rToCheck {
	// 		diff := down - rToCheck
	// 		perSide := diff
	// 		ranges = append(ranges, Range{sensor.pos.c - perSide, sensor.pos.c + perSide})
	// 		// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - perSide, sensor.pos.c + perSide)
	// 	} else {
	// 		// fmt.Printf("\n")
	// 	}
	// }
	// sort.Slice(ranges, func(i, j int) bool {
	// 	if ranges[i].start == ranges[j].start {
	// 		return ranges[i].end < ranges[j].end
	// 	}
	// 	return ranges[i].start < ranges[j].start
	// })
	// // mergedRanges := make([]Range, 0)
	// // used := make([]bool, len(ranges))
	//    r := ranges[0]
	// for i := 1; i < len(ranges); i++ {
	//        MinSelf(&r.start, ranges[i].start)
	//        MaxSelf(&r.end, ranges[i].end)
	// }
	// fmt.Printf("%v\n", r)
	//    answer := r.end - r.start + 1 - len(toRemove)
	//    log.Printf("answer=%d\n", answer)

	minR, maxR, minC, maxC := math.MaxInt, 0, math.MaxInt, 0
	grid := make(map[int]map[int]byte)
	for _, sensor := range sensors {
		c := sensor.pos.c
		MaxSelf(&maxC, c)
		MinSelf(&minC, c)
		r := sensor.pos.r
		MaxSelf(&maxR, r)
		MinSelf(&minR, r)
		if _, ok := grid[r]; !ok {
			grid[r] = make(map[int]byte)
		}
		grid[r][c] = 'S'
		c = sensor.beacon.c
		MaxSelf(&maxC, c)
		MinSelf(&minC, c)
		r = sensor.beacon.r
		MaxSelf(&maxR, r)
		MinSelf(&minR, r)
		if _, ok := grid[r]; !ok {
			grid[r] = make(map[int]byte)
		}
		grid[r][c] = 'B'
	}

	answer := 0

	for _, sensor := range sensors {
		rd := DistR(sensor.pos, sensor.beacon)
		cd := DistC(sensor.pos, sensor.beacon)
		d := rd + cd
		for r := sensor.pos.r - d; r <= sensor.pos.r+d; r++ {
			for c := sensor.pos.c - d; c <= sensor.pos.c+d; c++ {
				p := Point{r, c}
				prd := DistR(p, sensor.pos)
				pcd := DistC(p, sensor.pos)
				// fmt.Printf("sensor=(%d,%d) beacon=(%d,%d) dist_beacon=(%d,%d) point=(%d,%d) dist_point(%d,%d)\n", sensor.pos.r, sensor.pos.c, sensor.beacon.r, sensor.beacon.c, rd, cd, r, c, prd, pcd)
				if prd+pcd <= rd+cd {
					// fmt.Printf("ok\n")
					if _, ok := grid[r]; !ok {
						grid[r] = make(map[int]byte)
					}
					if _, ok := grid[r][c]; !ok {
						grid[r][c] = '#'
					}
					MaxSelf(&maxR, r)
					MinSelf(&minR, r)
					MaxSelf(&maxC, c)
					MinSelf(&minC, c)
				} else {
					// fmt.Printf("not ok\n")
				}
			}
		}
	}
	fmt.Printf("ok, now looking\n")
	for c := minC; c <= maxC; c++ {
		if _, ok := grid[rToCheck]; ok {
			if val, ook := grid[rToCheck][c]; ook && val == '#' {
				answer++
			}
		}
	}
    PrintState(grid, minR, maxR, minC, maxC)
	log.Printf("answer=%d\n", answer)
}
