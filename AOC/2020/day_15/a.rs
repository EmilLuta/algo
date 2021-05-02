use std::collections::HashMap;
use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut input: String = fs::read_to_string(&args[1]).unwrap();
    input.pop();
    let starting_numbers: Vec<usize> = input
        .split(",")
        .map(|i| i.to_string().parse().unwrap())
        .collect();
    let mut mem: HashMap<usize, usize> = HashMap::new();
    for i in 0..starting_numbers.len() {
        mem.insert(starting_numbers[i], i);
    }
    let mut i = starting_numbers.len();
    let mut prev = 0;
    // println!("prev = {}, mem = {:#?}", prev, mem);
    // println!("i = {}", i);
    while i < 30000000 {
        let copy = prev;
        prev = match mem.get(&prev) {
            Some(val) => i - val,
            None => 0,
        };
        mem.insert(copy, i);
        // println!("i = {}, prev = {}", i + 1, prev);
        i += 1;
    }
    println!("{:#?}", prev);
}
