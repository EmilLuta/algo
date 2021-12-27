use std::env;
use std::fs;

fn get_int(v: Vec<u8>) -> i32 {
    let mut answer: i32 = 0;
    for i in 0..v.len() {
        answer = answer * 2 + (v[i] as i32);
    }
    answer
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let mut gamma: Vec<u8> = vec![0; lines[0].len()];
    let mut epsilon: Vec<u8> = vec![0; lines[0].len()];
    let mut balance: Vec<i32> = vec![0; lines[0].len()];
    for line in lines {
        for (i, c) in line.chars().enumerate() {
            balance[i] += match c {
                '1' => 1,
                '0' => -1,
                _ => panic!("Expecting only 0 or 1"),
            };
        }
    }
    for i in 0..balance.len() {
        if balance[i] < 0 {
            gamma[i] = 0;
            epsilon[i] = 1;
        } else if balance[i] > 0 {
            gamma[i] = 1;
            epsilon[i] = 0;
        } else {
            panic!("Expecting no ties on balance");
        }
    }
    println!("gamma = {:?}", gamma);
    println!("epsilon = {:?}", epsilon);
    let gamma = get_int(gamma);
    let epsilon = get_int(epsilon);
    println!("answer = {}", gamma * epsilon);
}
