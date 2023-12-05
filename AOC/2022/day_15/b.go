package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"sort"
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
	for i, line := range data {
		sensor, err := NewSensor(line)
		if err != nil {
			log.Fatalf("failed to create sensor: %v\n", err)
			return
		}
		sensors[i] = sensor
	}
	N := 4000000
	// N := 20
	ranges := make([][]Range, N+1)
	for _, sensor := range sensors {
		dr := DistR(sensor.pos, sensor.beacon)
		dc := DistC(sensor.pos, sensor.beacon)
		d := dr + dc
		down := sensor.pos.r + d
		up := sensor.pos.r - d
		// fmt.Printf("sensor=(%d,%d) beacon=(%d,%d) dist_beacon=(%d,%d) overall_dist=%d up=%d down=%d ", sensor.pos.r, sensor.pos.c, sensor.beacon.r, sensor.beacon.c, dr, dc, d, up, down)
		for rToCheck := 0; rToCheck <= N; rToCheck++ {
			if sensor.pos.r == rToCheck {
				ranges[rToCheck] = append(ranges[rToCheck], Range{sensor.pos.c - d, sensor.pos.c + d})
				// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - (sensor.pos.r - d), sensor.pos.c + (sensor.pos.r + d))
			} else if up <= rToCheck && sensor.pos.r > rToCheck {
				diff := rToCheck - up
				perSide := diff
				ranges[rToCheck] = append(ranges[rToCheck], Range{sensor.pos.c - perSide, sensor.pos.c + perSide})
				// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - perSide, sensor.pos.c + perSide)
			} else if down >= rToCheck && sensor.pos.r < rToCheck {
				diff := down - rToCheck
				perSide := diff
				ranges[rToCheck] = append(ranges[rToCheck], Range{sensor.pos.c - perSide, sensor.pos.c + perSide})
				// fmt.Printf("range=[%d,%d]\n", sensor.pos.c - perSide, sensor.pos.c + perSide)
			} else {
				// fmt.Printf("\n")
			}
		}
	}
	fmt.Printf("done\n")
	for x := 0; x < len(ranges); x++ {
		sort.Slice(ranges[x], func(i, j int) bool {
			if ranges[x][i].start == ranges[x][j].start {
				return ranges[x][i].end < ranges[x][j].end
			}
			return ranges[x][i].start < ranges[x][j].start
		})
	}
	fmt.Printf("sort\n")
	// m := make([][]byte, N + 1)
	// for i := 0; i <= N; i++ {
	//     m[i] = make([]byte, N + 1)
	//     for j := 0; j <= N; j++ {
	//         m[i][j] = '.'
	//     }
	// }
	// for r := 0; r <= N; r++ {
	//     for _, ra := range ranges[r] {
	//         for c := ra.start; c <= ra.end; c++ {
	//             if 0 <= c && c <= N {
	//                 m[r][c] = '#'
	//             }
	//         }
	//     }
	// }
	// for r := 0; r <= N; r++ {
	//     for c := 0; c <= N; c++ {
	//         fmt.Printf("%c", m[r][c])
	//     }
	//     fmt.Printf("\n")
	// }
	for i := 0; i <= N; i++ {
		mergedRanges := make([]Range, 0)
		used := make([]bool, len(ranges))
		for r1 := 0; r1 < len(ranges[i]); r1++ {
			r := ranges[i][r1]
			if !used[r1] {
				for r2 := r1 + 1; r2 < len(ranges[i]); r2++ {
					if Overlap(r, ranges[i][r2]) {
						MinSelf(&r.start, ranges[i][r2].start)
						MaxSelf(&r.end, ranges[i][r2].end)
						used[r2] = true
					}
				}
				mergedRanges = append(mergedRanges, r)
			}
			used[r1] = true
		}
		if len(mergedRanges) > 1 {
			fmt.Printf("r = %d, %v\n", i, mergedRanges)
            fmt.Printf("answer = %d\n", (mergedRanges[0].end + 1 * N) + i)
			// fmt.Printf("r = %d, %v\n", i, ranges[i])
		}
        if i % 100000 == 0 {
            fmt.Printf("done row %d\n", i)
        }
	}
}
