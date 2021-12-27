use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let numbers: Vec<i32> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string().parse::<i32>().unwrap())
        .collect();
    let mut answer = 0;
    for i in 1..numbers.len() {
        if numbers[i] > numbers[i - 1] {
            answer += 1;
        }
    }
    println!("answer = {}", answer);
}
