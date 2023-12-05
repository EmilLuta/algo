use std::env;
use std::collections::HashMap;
use std::fs;

const NUMBERS: [&str; 10] = [
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
];



fn parse_number(raw_line: &[u8], index: usize) -> (usize, Option<i32>) {
    match raw_line[index] {
        48..=57 => (index + 1, Some(raw_line[index] as i32 - 48)),
        b'o' | b't' | b'f' | b's' | b'e' | b'n' => {
            let number_mapping: HashMap<&str, i32> = [
                ("zero", 0),
                ("one", 1),
                ("two", 2),
                ("three", 3),
                ("four", 4),
                ("five", 5),
                ("six", 6),
                ("seven", 7),
                ("eight", 8),
                ("nine", 9),
            ].iter().cloned().collect();
            for no in NUMBERS {
                let number = no.as_bytes();
                let end = index + number.len();
                if end > raw_line.len() {
                    continue;
                }
                let mut ok = true;
                for curr_index in index..end {
                    if raw_line[curr_index] != number[curr_index - index] {
                        ok = false;
                    }
                }
                if ok {
                    let raw_number = std::str::from_utf8(&raw_line[index..end]).unwrap();
                    return (index + 1, Some(*number_mapping.get(raw_number).unwrap()));
                }
            }
            (index + 1, None)
        }
        _ => (index + 1, None),
    }
}

fn extract_number(line: &str) -> Result<i32, String> {
    let raw_line = line.as_bytes();
    let n = raw_line.len();
    let mut first_digit = None;
    let mut last_digit = None;
    let mut i = 0;
    let mut number: Option<i32>;
    while i < n {
        (i, number) = parse_number(raw_line, i);
        if number.is_some() {
            if first_digit.is_none() {
                first_digit = number;
                continue;
            }
            last_digit = number;
        }
    }
    if let Some(first) = first_digit {
        let mut answer = first;
        if let Some(last) = last_digit {
            answer = answer * 10 + last;
        } else {
            answer = answer * 10 + first;
        }
        return Ok(answer);
    }
    Err(String::from("invalid string"))
}
fn main() {
    let args: Vec<String> = env::args().collect();
    let answer: i32 = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| extract_number(line).unwrap())
        .sum();
    println!("answer = {:#?}", answer);
}
