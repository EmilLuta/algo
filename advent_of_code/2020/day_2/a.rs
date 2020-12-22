use std::env;
use std::fs;

fn process_line(line: &[u8]) -> bool {
    let n: usize = line.len();
    let mut min: i32 = 0;
    let mut max: i32 = 0;
    let mut i: usize = 0;
    while '0' as u8 <= line[i] && line[i] <= '9' as u8  {
        min = min * 10 + (line[i] - '0' as u8) as i32;
        i = i + 1;
    }
    i = i + 1;
    while '0' as u8 <= line[i] && line[i] <= '9' as u8 {
        max = max * 10 + (line[i] - '0' as u8) as i32;
        i = i + 1;
    }
    i = i + 1;
    let c: char = line[i] as char;
    let mut count: i32 = 0;
    i = i + 2;
    while i < n {
        if line[i] as char  == c {
            // println!("char = {}, line[i] = {}", c, line[i] as char);
            count = count + 1;
        }
        i = i + 1;
    }
    println!("min = {}, count = {}, max = {}", min, count, max);
    min <= count && count <= max
}

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("{}", 
        fs::read_to_string(&args[1]).unwrap().lines()
            .filter(|line| { process_line(line.to_string().as_bytes()) })
            .count());
}