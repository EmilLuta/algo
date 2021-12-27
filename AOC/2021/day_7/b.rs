use std::cmp::min;
use std::env;
use std::fs;

fn get_cost(val: i64) -> i64 {
    val * (val + 1) / 2
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let inp: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let pos: Vec<i64> = inp[0].split(",").map(|d| d.parse().unwrap()).collect();
    let mut answer: i64 = 1e9 as i64;
    for i in 0..5000 {
        let mut curr = 0;
        for p in &pos {
            curr += get_cost((p - i).abs());
        }
        answer = min(answer, curr);
    }
    println!("answer = {}", answer);
}
