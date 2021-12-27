use std::collections::HashMap;
use std::env;
use std::fs;

#[derive(Debug)]
struct Line {
    data: String,
}

impl Line {
    fn new(s: &str) -> Line {
        Line {
            data: s.to_string(),
        }
    }

    fn get_corrupted(&self, val_map: &HashMap<char, i64>, char_map: &HashMap<char, char>) -> i64 {
        let mut stack: Vec<char> = vec![];
        for c in self.data.chars() {
            if char_map.contains_key(&c) {
                if stack.len() == 0 {
                    return *val_map.get(&c).unwrap();
                }
                let last_i = stack.len() - 1;
                if stack[last_i] != *char_map.get(&c).unwrap() {
                    return *val_map.get(&c).unwrap();
                }
                stack.pop();
                continue;
            }
            stack.push(c);
        }
        0
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<Line> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Line::new(line))
        .collect();
    let val_map: HashMap<char, i64> =
        HashMap::from([(')', 3), (']', 57), ('}', 1197), ('>', 25137)]);
    let char_map: HashMap<char, char> =
        HashMap::from([(')', '('), (']', '['), ('}', '{'), ('>', '<')]);
    let mut answer = 0;
    for line in &lines {
        answer += line.get_corrupted(&val_map, &char_map);
    }
    println!("answer = {}", answer);
}
