use std::collections::{HashMap, HashSet};
use std::env;
use std::fs;
use std::iter::FromIterator;
use std::iter::Iterator;

#[derive(Debug)]
struct Line {
    left: Vec<String>,
    right: Vec<String>,
}

fn sort_string(unsorted: &str) -> String {
    let mut chars: Vec<char> = unsorted.chars().collect();
    chars.sort_by(|a, b| a.cmp(b));
    String::from_iter(chars)
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
            .map(|val| sort_string(val))
            .collect();
        Line { left, right }
    }

    fn got(&self, chars: &Vec<char>, from: &HashSet<char>) -> i64 {
        let mut count = 0;
        for c in chars {
            if from.contains(c) {
                count += 1;
            }
        }
        count
    }

    fn get_mapping(&self) -> HashMap<String, i64> {
        let mut mapping: HashMap<String, i64> = HashMap::new();
        let mut per_size: HashMap<usize, Vec<String>> = HashMap::new();
        for dig in &self.left {
            let digits = per_size.entry(dig.len()).or_insert(vec![]);
            digits.push(dig.clone());
        }
        mapping.insert(sort_string(&per_size.get(&2).unwrap()[0]), 1);
        mapping.insert(sort_string(&per_size.get(&3).unwrap()[0]), 7);
        mapping.insert(sort_string(&per_size.get(&4).unwrap()[0]), 4);
        mapping.insert(sort_string(&per_size.get(&7).unwrap()[0]), 8);
        let seven: HashSet<char> = per_size.get(&3).unwrap()[0].chars().collect();
        let four: HashSet<char> = per_size.get(&4).unwrap()[0].chars().collect();
        for with_5 in per_size.get(&5).unwrap() {
            let vec_with_5: Vec<char> = with_5.chars().collect();
            let got_with_seven = self.got(&vec_with_5, &seven);
            let got_with_four = self.got(&vec_with_5, &four);
            if got_with_seven == 3 && got_with_four == 3 {
                mapping.insert(sort_string(with_5), 3);
            }
            if got_with_seven == 2 && got_with_four == 2 {
                mapping.insert(sort_string(with_5), 2);
            }
            if got_with_seven == 2 && got_with_four == 3 {
                mapping.insert(sort_string(with_5), 5);
            }
        }
        for with_6 in per_size.get(&6).unwrap() {
            let vec_with_6: Vec<char> = with_6.chars().collect();
            let got_with_seven = self.got(&vec_with_6, &seven);
            let got_with_four = self.got(&vec_with_6, &four);
            if got_with_seven == 2 && got_with_four == 3 {
                mapping.insert(sort_string(with_6), 6);
            }
            if got_with_seven == 3 && got_with_four == 4 {
                mapping.insert(sort_string(with_6), 9);
            }
            if got_with_seven == 3 && got_with_four == 3 {
                mapping.insert(sort_string(with_6), 0);
            }
        }

        mapping
    }

    fn value(&self) -> i64 {
        let mapping = self.get_mapping();
        let mut answer = 0;
        for val in &self.right {
            let curr = mapping.get(val).unwrap();
            answer = answer * 10 + curr;
        }
        answer
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<Line> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Line::new(line))
        .collect();
    let mut answer = 0;
    for line in &lines {
        answer += line.value();
    }
    println!("answer = {:?}", answer);
}
