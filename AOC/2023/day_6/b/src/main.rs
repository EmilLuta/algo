use std::env;
use std::fs;

fn get_num(line: &str) -> i64 {
    line.split(':')
        .skip(1)
        .map(|entry| entry.trim())
        .flat_map(|entry| entry.split_whitespace())
        .collect::<Vec<&str>>()
        .join("")
        .parse::<i64>()
        .unwrap()
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let time = get_num(&lines[0]);
    let distance = get_num(&lines[1]);
    let mut ways = 0;
    for load_time in 1..time - 1 {
        if load_time * (time - load_time) > distance {
            ways += 1;
        }
    }
    println!("answer = {ways:?}");
}
