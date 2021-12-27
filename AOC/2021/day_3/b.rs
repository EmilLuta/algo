use std::collections::HashSet;
use std::env;
use std::fs;

fn get_rating(numbers: &Vec<i32>, take_bigger: bool, len: usize) -> i32 {
    let mut indices: HashSet<usize> = (0..numbers.len()).map(|n| n as usize).collect();
    let mut bit_index = len - 1;
    while indices.len() > 1 {
        let bit = 1 << bit_index;
        let mut balance = 0;
        for index in &indices {
            if numbers[*index] & bit != 0 {
                balance += 1;
            } else {
                balance -= 1;
            }
        }
        let mut new_indices: HashSet<usize> = HashSet::new();
        for index in &indices {
            let curr = numbers[*index];
            if take_bigger {
                if balance < 0 {
                    if curr & bit == 0 {
                        new_indices.insert(*index);
                    }
                } else {
                    if curr & bit != 0 {
                        new_indices.insert(*index);
                    }
                }
            } else {
                if balance < 0 {
                    if curr & bit != 0 {
                        new_indices.insert(*index);
                    }
                } else {
                    if curr & bit == 0 {
                        new_indices.insert(*index);
                    }
                }
            }
        }
        indices = new_indices;
        bit_index -= 1;
    }
    for index in indices {
        return numbers[index];
    }
    0
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let len = lines[0].len();
    let lines: Vec<i32> = lines
        .iter()
        .map(|line| i32::from_str_radix(line, 2).unwrap())
        .collect();
    let oxygen = get_rating(&lines, true, len);
    let c02 = get_rating(&lines, false, len);
    println!("oxygen = {}", oxygen);
    println!("c02 = {}", c02);
    println!("answer = {}", oxygen * c02);
}
