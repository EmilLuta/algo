use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut numbers: Vec<i32> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n")
        .filter(|line| !line.is_empty())
        .map(|line| line.parse::<i32>().unwrap())
        .collect();
    numbers.sort();
    let mut threes: i32 = 1;
    let mut ones: i32 = 0;
    let n: usize = numbers.len();
    if numbers[0] == 1 {
        ones += 1;
    }
    if numbers[1] == 3 {
        threes += 1;
    }
    for i in 1..n {
        match numbers[i] - numbers[i - 1] {
            3 => { threes += 1; },
            1 => { ones += 1; },
            _ => {},
        }
    }
    println!("{}", threes * ones);
}
