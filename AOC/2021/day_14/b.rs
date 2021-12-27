use std::cmp::{max, min};
use std::collections::HashMap;
use std::env;
use std::fs;

struct Template {
    polymer: HashMap<(char, char), i64>,
    rules: HashMap<(char, char), char>,
    start: char,
    end: char,
}

impl Template {
    fn new(data: Vec<String>) -> Template {
        let n = data.len();
        let raw_poly: Vec<char> = data[0].chars().collect();
        let mut polymer: HashMap<(char, char), i64> = HashMap::new();
        for i in 1..raw_poly.len() {
            *polymer.entry((raw_poly[i - 1], raw_poly[i])).or_insert(0) += 1;
        }
        let start = raw_poly[0];
        let end = raw_poly[raw_poly.len() - 1];
        let mut rules: HashMap<(char, char), char> = HashMap::new();
        for i in 2..n {
            let mut iter = data[i].split(" -> ");
            let from: Vec<char> = iter.next().unwrap().chars().collect();
            let to: Vec<char> = iter.next().unwrap().chars().collect();
            rules.insert((from[0], from[1]), to[0]);
        }
        Template {
            polymer,
            rules,
            start,
            end,
        }
    }

    fn expand(&mut self) {
        let mut polymer: HashMap<(char, char), i64> = HashMap::new();
        for (key, val) in self.polymer.iter() {
            let c = *self.rules.get(key).unwrap();
            *polymer.entry((key.0, c)).or_insert(0) += val;
            *polymer.entry((c, key.1)).or_insert(0) += val;
        }
        self.polymer = polymer;
    }

    fn get_max_minus_min_occ(&self) -> i64 {
        let mut occ: HashMap<char, i64> = HashMap::new();
        for (key, val) in self.polymer.iter() {
            *occ.entry(key.0).or_insert(0) += val;
            *occ.entry(key.1).or_insert(0) += val;
        }
        *occ.entry(self.start).or_insert(0) += 1;
        *occ.entry(self.end).or_insert(0) += 1;
        let mut mini = std::i64::MAX;
        let mut maxi = 0;
        for (_, v) in occ.iter() {
            mini = min(mini, *v / 2);
            maxi = max(maxi, *v / 2);
        }
        maxi - mini
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let mut template = Template::new(lines);
    for _ in 0..40 {
        template.expand();
    }
    println!("answer = {}", template.get_max_minus_min_occ());
}
