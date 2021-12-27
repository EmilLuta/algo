use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let mut horizontal = 0;
    let mut depth = 0;
    for line in lines {
        let mut iterator = line.split(" ");
        let direction = iterator.next().unwrap();
        let value = iterator.next().unwrap().parse::<i32>().unwrap();
        match direction {
            "forward" => horizontal += value,
            "down" => depth += value,
            "up" => depth -= value,
            _ => panic!("invalid direction"),
        }
    }
    println!("answer = {}", depth * horizontal);
}
