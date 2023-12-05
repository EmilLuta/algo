package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
	// "time"
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

func ParseLine(line string) (string, []string, int, error) {
	node := line[6:8]
	rateSplit := strings.Split(line, ";")
	rate, err := strconv.Atoi(rateSplit[0][23:])
	if err != nil {
		return "", []string{}, -1, errors.New(fmt.Sprintf("failed to convert rate %s: %v", rateSplit[0][23:], err))
	}
	var childrenS string
	if strings.HasPrefix(rateSplit[1], " tunnels") {
		childrenSplit := strings.Split(rateSplit[1], " tunnels lead to valves ")
		childrenS = childrenSplit[1]
	} else {
		childrenSplit := strings.Split(rateSplit[1], " tunnel leads to valve ")
		childrenS = childrenSplit[1]
	}
	children := strings.Split(childrenS, ", ")
	return node, children, rate, nil
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type State struct {
	node     string
	rate     int
	elapsed  int
	cameFrom string
}

const DEADLINE int = 30

func Search(state State, turned map[string]bool, graph map[string]map[string]bool, valveRates map[string]int) int {
	if state.elapsed == DEADLINE {
		return state.rate
	}
	answer := 0
	if !turned[state.node] {
		turned[state.node] = true
		answer = Max(answer, Search(State{state.node, state.rate + valveRates[state.node], state.elapsed + 1, state.node}, turned, graph, valveRates))
		turned[state.node] = false
	}
	for child := range graph[state.node] {
        if child == state.cameFrom {
            continue
        }
		answer = Max(answer, Search(State{child, state.rate, state.elapsed + 1, state.node}, turned, graph, valveRates))
	}
	return answer
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	graph := make(map[string]map[string]bool)
	valveRates := make(map[string]int)
	for _, line := range data {
		node, children, rate, err := ParseLine(line)
		if err != nil {
			log.Fatalf("couldn't parse line: %v\n", err)
			return
		}
		if _, ok := graph[node]; !ok {
			graph[node] = make(map[string]bool)
		}
		for _, child := range children {
			graph[node][child] = true
			if _, ok := graph[child]; !ok {
				graph[child] = make(map[string]bool)
			}
			graph[child][node] = true
		}
		valveRates[node] = rate
	}
	turned := make(map[string]bool)
	turned["AA"] = true
	answer := Search(State{"AA", 0, 0, ""}, turned, graph, valveRates)
	// answer := 0
	// queue := []State{}
	// queue = append(queue, State{"AA", 0, 0, make(map[string]bool)})
	// index := 0
	// for index < len(queue) {
	//        fmt.Printf("index = %d, %v\n", index, queue)
	//        time.Sleep(time.Second)
	// 	state := queue[index]
	// 	index++
	// 	if state.elapsed == deadline {
	// 		answer = Max(answer, state.rate)
	// 		continue
	// 	}
	// 	if !state.turned[state.node] {
	// 		newTurned := CopyTurned(state.turned)
	// 		newTurned[state.node] = true
	// 		newState := State{state.node, state.rate + valveRate[state.node], state.elapsed + 1, newTurned}
	// 		queue = append(queue, newState)
	// 	}
	// 	for child := range graph[state.node] {
	// 		newState := State{child, state.rate, state.elapsed + 1, CopyTurned(state.turned)}
	// 		queue = append(queue, newState)
	// 	}
	// }
	log.Printf("answer=%d\n", answer)
}
