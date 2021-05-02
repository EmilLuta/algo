use std::{env, fs};

fn add_paran(line: String) -> String {
    // println!("running on line = {:#?}", line);
    let n = line.len();
    let mut new_s: String = String::new();
    let mut i: usize = 0;
    let mut j: usize = 0;
    while i < n {
        let mut c: char = line.as_bytes()[i] as char;
        match c {
            '+' => {
                let mut x: i32 = j as i32 - 2;
                let mut count = 0;
                while x >= 0 {
                    c = new_s.as_bytes()[x as usize] as char;
                    if count == 0 && (c == ' ' || c == '(') {
                        break;
                    }
                    if c == '(' {
                        count -= 1;
                    }
                    if c == ')' {
                        count += 1;
                    }
                    x -= 1;
                }
                // println!(
                //     "left hand side looks like this: from {:#?} we do this + {:#?} + ( +  {:#?}; split is at {:#?}",
                //     &new_s,
                //     &new_s[..x as usize + 1],
                //     &new_s[x as usize + 1..],
                //     x
                // );
                let x = x as usize;
                let mut buffer = String::new();
                buffer += &new_s[..x + 1];
                buffer += "(";
                buffer += &new_s[x + 1..];
                buffer += "+ ";
                new_s = buffer;
                i += 2;
                let start = i;
                if line.as_bytes()[i] as char == '(' {
                    let mut count = 0;
                    while i < n {
                        c = line.as_bytes()[i] as char;
                        if c == '(' {
                            count += 1;
                        }
                        if c == ')' {
                            count -= 1;
                        }
                        if count == 0 {
                            break;
                        }
                        i += 1;
                    }
                    // println!(
                    //     "right hand side looks like this: we add {:#?} at the end",
                    //     &line[start..i + 1]
                    // );
                    new_s += &add_paran((&line[start..i + 1]).to_string());
                    new_s += ")";
                } else {
                    while i < n {
                        c = line.as_bytes()[i] as char;
                        if c == ' ' || c == ')' {
                            break;
                        }
                        i += 1;
                    }
                    // println!(
                    //     "right hand side looks like this: we add {:#?} + ) + {:#?}",
                    //     &line[start..i],
                    //     &(line.as_bytes()[i] as char).to_string()
                    // );
                    new_s += &line[start..i];
                    new_s += ")";
                    if i < n {
                        new_s += &(line.as_bytes()[i] as char).to_string();
                    }
                }
            }
            _ => {
                new_s += &c.to_string();
            }
        }
        // println!("new_s = {:#?}", new_s);
        i += 1;
        j = new_s.len();
    }
    new_s
}

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
        let paran_line = add_paran(line.clone());
        let val: i64 = compute(paran_line.clone());
        println!("{} = {} = {}", val, line, paran_line);
        answer += val;
    }
    println!("answer = {}", answer);
}
