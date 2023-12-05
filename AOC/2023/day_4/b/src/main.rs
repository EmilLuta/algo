use std::collections::HashSet;
use std::env;
use std::fs;

struct Card {
    expected: HashSet<i32>,
    got: HashSet<i32>,
}

impl Card {
    fn parse(raw: &str) -> HashSet<i32> {
        let mut vals = HashSet::new();
        for raw_no in raw.as_bytes().chunks(3) {
            let mut val = 0;
            if raw_no[0] != 32 {
                val += (raw_no[0] - 48) as i32 * 10;
            }
            val += (raw_no[1] - 48) as i32;
            vals.insert(val);
        }
        vals
    }

    fn new(line: &str) -> Card {
        let raw_values = line.split(": ").nth(1).unwrap();
        let mut numbers = raw_values.split(" | ");
        let raw_got: &str = numbers.next().unwrap();
        let raw_expected: &str = numbers.next().unwrap();
        let got = Card::parse(raw_got);
        let expected = Card::parse(raw_expected);
        Card { expected, got }
    }

    fn score(&self) -> i32 {
        let mut score = 0;
        for val in &self.got {
            if self.expected.contains(val) {
                score += 1;
            }
        }
        score
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let cards: Vec<Card> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(Card::new)
        .collect();
    let mut vals = vec![0; cards.len() + 1];
    let mut counter = 0;
    let mut answer = 0;
    for (i, c) in cards.iter().enumerate() {
        counter += vals[i];
        answer += counter + 1;
        let score = c.score() as usize;
        vals[i + 1] += counter + 1;
        vals[i + 1 + score] -= counter + 1;
    }
    println!("answer = {answer:?}");
}

