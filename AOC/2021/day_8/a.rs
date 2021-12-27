use std::collections::HashSet;
use std::env;
use std::fs;

#[derive(Debug)]
struct Line {
    left: Vec<String>,
    right: Vec<String>,
}

impl Line {
    fn new(raw: &str) -> Line {
        let left_right: Vec<&str> = raw.split(" | ").collect();
        let left: Vec<String> = left_right[0]
            .split(" ")
            .map(|val| val.to_string())
            .collect();
        let right: Vec<String> = left_right[1]
            .split(" ")
            .map(|val| val.to_string())
            .collect();
        Line { left, right }
    }

    fn get_unique_from_right(&self, uniq: &HashSet<usize>) -> i64 {
        let mut unique: i64 = 0;
        for val in &self.right {
            if uniq.contains(&val.len()) {
                unique += 1;
            }
        }
        unique
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<Line> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Line::new(line))
        .collect();
    let uniq: HashSet<usize> = vec![2, 3, 4, 7].into_iter().collect();
    let mut answer = 0;
    for line in &lines {
        answer += line.get_unique_from_right(&uniq);
    }
    println!("answer = {:?}", answer);
}
