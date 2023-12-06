use std::env;
use std::fs;

fn get_nums(line: &str) -> Vec<i64> {
    line.split(':')
        .skip(1)
        .map(|entry| entry.trim())
        .flat_map(|entry| entry.split_whitespace())
        .map(|entry| entry.parse::<i64>().unwrap())
        .collect()
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let times = get_nums(&lines[0]);
    let distances = get_nums(&lines[1]);
    let n = times.len();
    let mut answer = 1;
    for i in 0..n {
        let mut ways = 0;
        let time = times[i];
        let dist = distances[i];
        for load_time in 1..time - 1 {
            if load_time * (time - load_time) > dist {
                ways += 1;
            }
        }
        answer *= ways;
    }
    println!("answer = {answer:?}");
}
