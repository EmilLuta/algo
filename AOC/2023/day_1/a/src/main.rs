use std::env;
use std::fs;

fn extract_number(line: &str) -> Result<i32, String> {
    let mut first_digit = None;
    let mut last_digit = None;
    for c in line.chars() {
        if c.is_ascii_digit() {
            if first_digit.is_none() {
                first_digit = Some(c.to_digit(10).unwrap());
                continue;
            }
            last_digit = Some(c.to_digit(10).unwrap());
        }
    }
    println!("first_digit = {:?} and last_digit = {:?}", first_digit, last_digit);
    println!("line = {:?}", line);
    if let Some(first) = first_digit {
        let mut answer = first as i32;
        if let Some(last) = last_digit {
            answer = answer * 10 + last as i32;
        } else {
            answer = answer * 10 + first as i32;
        }
        println!("returning {:?}", answer);
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
