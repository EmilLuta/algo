package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
	"strings"
)

func loadData() (map[int][]int, map[int][]int) {
	graph := make(map[int][]int)
	revGraph := make(map[int][]int)
	file, err := os.Open("input.txt")
	// file, err := os.Open("test.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		data := strings.Split(scanner.Text(), " ")
		x, err := strconv.Atoi(data[0])
		if err != nil {
			log.Fatal(err)
		}
		y, err := strconv.Atoi(data[1])
		if err != nil {
			log.Fatal(err)
		}
		graph[x] = append(graph[x], y)
		revGraph[y] = append(revGraph[y], x)
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
	return graph, revGraph
}

const n int = 875714

var t, start int
var visitedOrder, visitedComponent [n + 1]bool
var graph, revGraph, mappedGraph map[int][]int
var f, leader [n + 1]int

func dfsOrder(node int) {
	visitedOrder[node] = true
	for _, child := range revGraph[node] {
		if !visitedOrder[child] {
			dfsOrder(child)
		}
	}
	t++
	f[node] = t
}

func dfsComponent(node int) {
	visitedComponent[node] = true
	leader[node] = start
	for _, child := range mappedGraph[node] {
		if !visitedComponent[child] {
			dfsComponent(child)
		}
	}
}

func initGraph() {
	graph, revGraph = loadData()
	// graph = map[int][]int{
	// 	1: []int{4},
	// 	2: []int{8},
	// 	3: []int{6},
	// 	4: []int{7},
	// 	5: []int{2},
	// 	6: []int{9},
	// 	7: []int{1},
	// 	8: []int{5, 6},
	// 	9: []int{3, 7},
	// }
	// revGraph = map[int][]int{
	// 	1: []int{7},
	// 	7: []int{4, 9},
	// 	4: []int{1},
	// 	9: []int{6},
	// 	6: []int{8, 3},
	// 	3: []int{9},
	// 	8: []int{2},
	// 	2: []int{5},
	// 	5: []int{8},
	// }
	mappedGraph = map[int][]int{}
}

func main() {
	initGraph()
	for i := n; i > 0; i-- {
		if !visitedOrder[i] {
			dfsOrder(i)
		}
	}

	for key := range graph {
		for _, value := range graph[key] {
			mappedKey := f[key]
			mappedValue := f[value]
			_, ok := mappedGraph[mappedKey]
			if !ok {
				mappedGraph[mappedKey] = []int{}
			}
			mappedGraph[mappedKey] = append(mappedGraph[mappedKey], mappedValue)
		}
	}

	for i := n; i > 0; i-- {
		if !visitedComponent[i] {
			start = i
			dfsComponent(i)
		}
	}
	counter := map[int]int{}
	for _, element := range leader[1:] {
		counter[element]++
	}
	values := make([]int, 0, len(counter))
	for key := range counter {
		values = append(values, counter[key])
	}
	sort.Slice(values, func(i, j int) bool {
		return values[i] < values[j]
	})
	fmt.Println(values)
}
