use std::{env, fs};

fn compute(line: String) -> i64 {
    let n: usize = line.len();
    let mut i: usize = 0;
    let mut op: char = '+';
    let mut answer: i64 = 0;
    while i < n {
        let mut c: char = line.as_bytes()[i] as char;
        match c {
            '(' => {
                i += 1;
                let start = i;
                let mut count = 1;
                while count != 0 {
                    c = line.as_bytes()[i] as char;
                    match c {
                        '(' => {
                            count += 1;
                        }
                        ')' => {
                            count -= 1;
                        }
                        _ => {}
                    }
                    i += 1;
                }
                let val = compute(line[start..i - 1].to_string());
                match op {
                    '+' => {
                        answer += val;
                    }
                    '*' => {
                        answer *= val;
                    }
                    _ => {
                        panic!("what operator '{}' is this? :o", op);
                    }
                }
            }
            '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => {
                let mut val: i64 = 0;
                while i < n {
                    c = line.as_bytes()[i] as char;
                    if !('0' <= c && c <= '9') {
                        break;
                    }
                    val = val * 10 + c.to_digit(10).unwrap() as i64;
                    i += 1;
                }
                match op {
                    '+' => {
                        answer += val;
                    }
                    '*' => {
                        answer *= val;
                    }
                    _ => {
                        panic!("what operator '{}' is this? :o", op);
                    }
                }
            }
            ')' => {
                panic!("unexpected '{}' char?", c);
            }
            '+' => {
                op = '+';
            }
            '*' => {
                op = '*';
            }
            ' ' => {}
            _ => {
                panic!("random '{}' char?", c);
            }
        }
        i += 1;
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
    let mut answer: i64 = 0;
    for line in lines {
        let val: i64 = compute(line.clone());
        println!("{} = {}", line, val);
        answer += val;
    }
    println!("answer = {}", answer);
}
