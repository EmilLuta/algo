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
    let mut current = numbers[0] + numbers[1] + numbers[2];
    for i in 3..numbers.len() {
        let new = current - numbers[i - 3] + numbers[i];
        if current < new {
            answer += 1;
        }
        current = new;
    }
    println!("answer = {}", answer);
}
