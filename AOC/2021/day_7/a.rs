use std::cmp::min;
use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let inp: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let pos: Vec<i64> = inp[0].split(",").map(|d| d.parse().unwrap()).collect();
    println!("pos = {:?}", pos);
    let mut answer: i64 = 1e9 as i64;
    for i in 0..5000 {
        let mut curr = 0;
        for p in &pos {
            curr += (p - i).abs();
        }
        answer = min(answer, curr);
    }
    println!("answer = {}", answer);
}
