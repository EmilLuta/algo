use std::env;
use std::fs;

fn process_line(line: &[u8]) -> bool {
    let mut index1: u8 = 0;
    let mut index2: u8 = 0;
    let mut i: usize = 0;
    while '0' as u8 <= line[i] && line[i] <= '9' as u8  {
        index1 = index1 * 10 + (line[i] - '0' as u8);
        i = i + 1;
    }
    i = i + 1;
    while '0' as u8 <= line[i] && line[i] <= '9' as u8  {
        index2 = index2 * 10 + (line[i] - '0' as u8);
        i = i + 1;
    }
    i = i + 1;
    let c: char = line[i] as char;
    i = i + 2;
    (line[i + index1 as usize] as char == c && line[i + index2 as usize] as char != c) || (line[i + index1 as usize] as char != c && line[i + index2 as usize] as char == c)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("{}", 
        fs::read_to_string(&args[1]).unwrap().lines()
            .filter(|line| { process_line(line.to_string().as_bytes()) })
            .count());
}