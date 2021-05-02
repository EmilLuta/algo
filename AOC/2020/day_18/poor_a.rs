use std::{env, fs};

fn compute(line: String) -> i64 {
    println!("called with line = {}", line);
    let n: usize = line.len();
    if n == 0 {
        return 0;
    }
    let mut answer: i64 = 0;
    let mut i: usize = 0;
    let mut c: char = line.as_bytes()[0] as char;
    match c {
        '(' => {
            let start = i + 1;
            let mut count = 1;
            i += 1;
            while count != 0 {
                c = line.as_bytes()[i] as char;
                if c == '(' {
                    count += 1;
                }
                if c == ')' {
                    count -= 1;
                }
                i += 1;
            }
            answer += compute(line[start..i - 1].to_string());
            i += 1;
        }
        _ => {
            while c != ' ' {
                println!("c = {}", c);
                answer = answer * 10 + c.to_digit(10).unwrap() as i64;
                i += 1;
                if i == n {
                    return answer;
                }
                c = line.as_bytes()[i] as char;
            }
            i += 1;
        }
    }
    if i >= n {
        return answer;
    }
    println!("i = {}, n = {}", i, n);
    let op: char = line.as_bytes()[i] as char;
    let second: i64 = compute(line[i + 2..].to_string());
    println!("{} {} {}", answer, op, second);
    match op {
        '+' => {
            answer += second;
        }
        '*' => {
            answer *= second;
        }
        _ => {
            panic!("at the disco!");
        }
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
        println!("line = {}", line);
        println!("ANSWER = \n\n\n {} \n\n\n", compute(line.clone()));
        answer += compute(line);
    }
    println!("{}", answer);
}
