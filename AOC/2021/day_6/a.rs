use std::collections::HashMap;
use std::env;
use std::fs;

fn state_after_day(state: &Vec<i8>, mut days: usize) -> usize {
    let mut map: HashMap<i8, i32> = HashMap::new();
    for s in state {
        *map.entry(*s).or_insert(0) += 1;
    }
    while days > 0 {
        days -= 1;
        let mut new_map: HashMap<i8, i32> = HashMap::new();
        for key in map.keys() {
            if *key == 0 {
                *new_map.entry(6).or_insert(0) += map[key];
                *new_map.entry(8).or_insert(0) += map[key];
                continue;
            }
            *new_map.entry(key - 1).or_insert(0) += map[key];
        }
        map = new_map;
    }
    let mut answer = 0;
    for key in map.keys() {
        answer += map[key] as usize;
    }
    answer
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let state: Vec<i8> = lines[0]
        .split(",")
        .map(|val| val.parse().unwrap())
        .collect();
    println!("answer = {}", state_after_day(&state, 80));
}
