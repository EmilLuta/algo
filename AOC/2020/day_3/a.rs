use std::env;
use std::fs;

fn trees_per_slope(lines: &Vec<String>, right: usize, down: usize) -> i64 {
    let n = lines.len();
    let m = lines[0].as_bytes().len();
    let mut i: usize = 0;
    let mut j: usize = 0;
    let mut answer: i64 = 0;
    while i < n - 1 {
        i = i + down;
        j = j + right;
        j = j % m;
        if lines[i].as_bytes()[j] == '#' as u8 {
            answer = answer + 1;
        }
    }
    println!("{}", answer);
    answer
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1]).unwrap()
        .lines().map(|line| {line.to_string()}).collect();
    let mut answer: i64 = 1;
    let slopes = vec!{(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)};
    for slope in slopes {
        let (right, down): (usize, usize) = slope;
        answer *= trees_per_slope(&lines, right, down);
    }
    println!("{}", answer);
}