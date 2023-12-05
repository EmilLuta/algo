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

type Monkey struct {
	items     []int
	operation func(int) int
	test      func(int, []Monkey)
	count     int
}

func parseMonkey(m []string) (Monkey, error) {
	monkey := Monkey{}
    monkey.count = 0
	itemSplit := strings.Split(m[1], "Starting items: ")
	items := strings.Split(itemSplit[1], ", ")
	monkey.items = make([]int, len(items))
	for i, item := range items {
		it, err := strconv.Atoi(item)
		if err != nil {
			return monkey, errors.New(fmt.Sprintf("couldn't create monkey as it can't convert item: %v\n", err))
		}
		monkey.items[i] = it
	}
	opSplit := strings.Split(m[2], "Operation: new = old ")
	opWith := strings.Split(opSplit[1], " ")
	op := opWith[0]
	monkey.operation = func(x int) int {
		switch op {
		case "+":
			if opWith[1] == "old" {
				return x + x
			}
			with, err := strconv.Atoi(opWith[1])
			if err != nil {
				panic("bad assumptions on conversion for operation")
			}
			return x + with
		case "*":
			if opWith[1] == "old" {
				return x * x
			}
			with, err := strconv.Atoi(opWith[1])
			if err != nil {
				panic("bad assumptions on conversion for operation")
			}
			return x * with
		default:
			log.Fatalf("encountered unexpected operation %v, panicing\n", op)
			panic("bad assumption strikes again")
		}
	}
	divSplit := strings.Split(m[3], "Test: divisible by ")
	div, err := strconv.Atoi(divSplit[1])
	if err != nil {
		return monkey, errors.New(fmt.Sprintf("couldn't create monkey as it can't convert test divisible: %v\n", err))
	}
	toTrueSplit := strings.Split(m[4], "If true: throw to monkey ")
	toTrue, err := strconv.Atoi(toTrueSplit[1])
	if err != nil {
		return monkey, errors.New(fmt.Sprintf("couldn't create monkey as it can't convert toTrue: %v\n", err))
	}
	toFalseSplit := strings.Split(m[5], "If false: throw to monkey ")
	toFalse, err := strconv.Atoi(toFalseSplit[1])
	if err != nil {
		return monkey, errors.New(fmt.Sprintf("couldn't create monkey as it can't convert toFalse: %v\n", err))
	}
	monkey.test = func(item int, monkeys []Monkey) {
		if item%div == 0 {
			monkeys[toTrue].items = append(monkeys[toTrue].items, item)
		} else {
			monkeys[toFalse].items = append(monkeys[toFalse].items, item)
		}
	}
	return monkey, nil
}

func printState(monkeys []Monkey) {
	for i := range monkeys {
		fmt.Printf("Monkey %d: ", i)
		for _, item := range monkeys[i].items {
			fmt.Printf("%d, ", item)
		}
		fmt.Printf("\n")
	}
    fmt.Printf("\n")
    for i := range monkeys {
		fmt.Printf("Monkey %d: count = %d\n", i, monkeys[i].count)
	}
    fmt.Printf("----\n")
}

func main() {
	data, err := getFileData()
	if err != nil {
		log.Fatalf("couldn't read input: %v\n", err)
		return
	}
	monkeys := make([]Monkey, len(data)/7+1)
	for i := 0; i < len(data); i += 7 {
		monkey, err := parseMonkey(data[i : i+7])
		if err != nil {
			log.Fatalf("couldn't parse monkey: %v\n", err)
			return
		}
		monkeys[i/7] = monkey
	}
    for i := 0; i < 20; i++ {
        for i := range monkeys {
            for _, item := range monkeys[i].items {
                val := monkeys[i].operation(item)
                val /= 3
                monkeys[i].test(val, monkeys)
                monkeys[i].count++
            }
            monkeys[i].items = []int{}
        }
        printState(monkeys)
    }
    sort.Slice(monkeys, func(i, j int) bool {
        return monkeys[i].count > monkeys[j].count
    })
    log.Printf("answer=%d\n", monkeys[0].count * monkeys[1].count)
}
