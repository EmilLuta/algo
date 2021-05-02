use std::collections::VecDeque;
use std::{env, fs};

fn get_players(lines: Vec<String>) -> (VecDeque<i64>, VecDeque<i64>) {
    let mut a: VecDeque<i64> = VecDeque::new();
    let mut b: VecDeque<i64> = VecDeque::new();
    let mut to_a: bool = false;
    for line in lines {
        if line.starts_with("Player") {
            to_a = !to_a;
            continue;
        }
        if line.len() == 0 {
            continue;
        }
        let val: i64 = line.parse().unwrap();
        if to_a {
            a.push_back(val);
        } else {
            b.push_back(val);
        }
    }
    (a, b)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let (mut a, mut b): (VecDeque<i64>, VecDeque<i64>) = get_players(lines);

    while a.len() > 0 && b.len() > 0 {
        let player_a = a.pop_front().unwrap();
        let player_b = b.pop_front().unwrap();
        if player_a > player_b {
            a.push_back(player_a);
            a.push_back(player_b);
        } else if player_a < player_b {
            b.push_back(player_b);
            b.push_back(player_a);
        } else {
            panic!("ai de plm!");
        }
        print!("a = [");
        for x in &a {
            print!("{:#?}, ", x);
        }
        println!("]");
        print!("b = [");
        for x in &b {
            print!("{:#?}, ", x);
        }
        println!("]");
    }
    let mut answer: i64 = 0;
    let arr: VecDeque<i64>;
    println!("a = {:#?}", a);
    println!("b = {:#?}", b);
    if a.len() < b.len() {
        arr = b;
    } else {
        arr = a;
    }
    let n = arr.len();
    for i in 0..n {
        println!("+ {:#?} * {:#?}", i + 1, arr[n - i - 1]);
        answer += ((i + 1) as i64) * arr[n - i - 1];
    }
    println!("answer = {:#?}", answer);
}
