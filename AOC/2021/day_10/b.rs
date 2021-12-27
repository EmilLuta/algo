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

    fn get_corrupted(
        &self,
        val_map: &HashMap<char, i64>,
        char_map: &HashMap<char, char>,
        rev_char_map: &HashMap<char, char>,
    ) -> Option<i64> {
        let mut stack: Vec<char> = vec![];
        for c in self.data.chars() {
            if rev_char_map.contains_key(&c) {
                if stack.len() == 0 {
                    return None;
                }
                let last_i = stack.len() - 1;
                if stack[last_i] != *rev_char_map.get(&c).unwrap() {
                    return None;
                }
                stack.pop();
                continue;
            }
            stack.push(c);
        }
        let mut answer = 0;
        for i in (0..stack.len()).rev() {
            answer = answer * 5 + *val_map.get(char_map.get(&stack[i]).unwrap()).unwrap();
        }
        println!("a = {}", answer);
        Some(answer)
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<Line> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Line::new(line))
        .collect();
    let val_map: HashMap<char, i64> = HashMap::from([(')', 1), (']', 2), ('}', 3), ('>', 4)]);
    let char_map: HashMap<char, char> =
        HashMap::from([('(', ')'), ('[', ']'), ('{', '}'), ('<', '>')]);
    let rev_char_map: HashMap<char, char> =
        HashMap::from([(')', '('), (']', '['), ('}', '{'), ('>', '<')]);
    let mut answer = vec![];
    for line in &lines {
        match line.get_corrupted(&val_map, &char_map, &rev_char_map) {
            Some(x) => answer.push(x),
            None => continue,
        }
    }
    answer.sort_by(|a, b| a.cmp(b));
    println!("answer = {}", answer[answer.len() / 2]);
}
