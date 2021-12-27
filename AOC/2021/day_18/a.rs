use std::env;
use std::fs;

const RADIX: u32 = 10;

#[derive(Debug)]
struct Number {
    number: Vec<(i64, i64)>,
}

impl Number {
    fn new(data: &str) -> Number {
        let mut number: Vec<(i64, i64)> = Vec::new();
        let mut level = 0;
        for c in data.chars() {
            match c {
                '[' => {
                    level += 1;
                }
                ']' => {
                    level -= 1;
                }
                o => {
                    if '0' <= o && o <= '9' {
                        number.push((
                            level,
                            o.to_digit(RADIX).expect("Character must be a digit") as i64,
                        ))
                    }
                }
            }
        }
        Number { number: number }
    }

    fn add(&mut self, other: &mut Number) {
        for i in 0..self.number.len() {
            self.number[i].0 += 1;
        }
        for i in 0..other.number.len() {
            self.number.push((other.number[i].0 + 1, other.number[i].1));
        }
        let mut changes = true;
        while changes {
            changes = false;
            let n = self.number.len();
            for i in 0..n {
                if self.number[i].0 > 4 {
                    changes = true;
                    if i == 0 {
                        self.number[i].0 -= 1;
                        self.number[i].1 = 0;
                        self.number[i + 2].1 += self.number[i + 1].1;
                        self.number[i + 1] = (-1, -1);
                        break;
                    } else if i + 1 == n - 1 {
                        self.number[i - 1].1 += self.number[i].1;
                        self.number[i].0 -= 1;
                        self.number[i].1 = 0;
                        self.number[i + 1] = (-1, -1);
                        break;
                    } else {
                        self.number[i - 1].1 += self.number[i].1;
                        self.number[i].0 -= 1;
                        self.number[i].1 = 0;
                        self.number[i + 2].1 += self.number[i + 1].1;
                        self.number[i + 1] = (-1, -1);
                        break;
                    }
                }
            }
            if changes {
                self.number.retain(|x| x != &(-1, -1));
                // println!("exploded = {:?}", self.number);
                continue;
            }
            for i in 0..n {
                if self.number[i].1 > 9 {
                    changes = true;
                    let half_down = self.number[i].1 / 2;
                    let half_up = (self.number[i].1 + 1) / 2;
                    let paran = self.number[i].0 + 1;
                    self.number[i].0 = paran;
                    self.number[i].1 = half_up;
                    self.number.insert(i, (paran, half_down));
                    break;
                }
            }
            if changes {
                self.number.retain(|x| x != &(-1, -1));
                // println!("split = {:?}", self.number);
                continue;
            }
        }
    }

    fn magnitude(&self) -> i64 {
        let mut magnitude = 0;
        for i in (0..self.number.len()).step_by(2) {
            magnitude += 3 * self.number[i].1 + 2 * self.number[i + 1].1
        }
        magnitude
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .expect("File exists")
        .lines()
        .map(|l| l.to_string())
        .collect();
    let mut number = Number::new(&lines[0]);
    for i in 1..lines.len() {
        let mut new_number = Number::new(&lines[i]);
        number.add(&mut new_number);
    }
    println!("number = {:?}", number);
    println!("answer = {}", number.magnitude());
}
