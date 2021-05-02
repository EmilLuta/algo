use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    assert!(lines.len() == 1);
    let values: Vec<i64> = lines[0]
        .split(" ")
        .map(|t| t.to_string().parse::<i64>().unwrap())
        .collect();
    assert!(values.len() == 2);
    let card: i64 = values[0];
    let door: i64 = values[1];
    const DIV: i64 = 20201227;
    let subject_number: i64 = 7;
    let mut card_curr: i64 = 1;
    let mut card_loop: i64 = 0;
    while card != card_curr {
        card_curr = card_curr * subject_number;
        card_curr = card_curr % DIV;
        card_loop += 1;
    }
    let mut door_curr: i64 = 1;
    let mut door_loop: i64 = 0;
    while door != door_curr {
        door_curr = door_curr * subject_number;
        door_curr = door_curr % DIV;
        door_loop += 1;
    }
    println!("card_loop = {}", card_loop);
    println!("door_loop = {}", door_loop);
    let subject_number = card;
    let mut card_curr = 1;
    for _ in 0..door_loop {
        card_curr = card_curr * subject_number;
        card_curr = card_curr % DIV;
    }
    let subject_number = door;
    let mut door_curr = 1;
    for _ in 0..card_loop {
        door_curr = door_curr * subject_number;
        door_curr = door_curr % DIV;
    }
    println!("door_curr = {}, card_curr = {}", door_curr, card_curr);
}
