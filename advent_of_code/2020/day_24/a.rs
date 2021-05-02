use std::collections::{HashMap, HashSet};
use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<Vec<char>> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string().chars().collect())
        .collect();
    let mut map: HashMap<(i64, i64), bool> = HashMap::new();
    for line in lines {
        let n: usize = line.len();
        let mut i: usize = 0;
        let mut pos: (i64, i64) = (0, 0);
        while i < n {
            match line[i] {
                'e' => {
                    pos = (pos.0 + 2, pos.1);
                    i += 1;
                }
                's' => {
                    assert!(i + 1 < n);
                    match line[i + 1] {
                        'e' => {
                            pos = (pos.0 + 1, pos.1 - 1);
                        }
                        'w' => {
                            pos = (pos.0 - 1, pos.1 - 1);
                        }
                        _ => {
                            panic!("unexpected character after s");
                        }
                    };
                    i += 2;
                }
                'w' => {
                    pos = (pos.0 - 2, pos.1);
                    i += 1;
                }
                'n' => {
                    assert!(i + 1 < n);
                    match line[i + 1] {
                        'e' => {
                            pos = (pos.0 + 1, pos.1 + 1);
                        }
                        'w' => {
                            pos = (pos.0 - 1, pos.1 + 1);
                        }
                        _ => {
                            panic!("unexpected character after n");
                        }
                    };
                    i += 2;
                }
                _ => {
                    panic!("unexpected character in file");
                }
            };
        }
        let count = map.entry(pos).or_insert(false);
        *count = !*count;
    }
    let mut current: HashSet<(i64, i64)> = HashSet::new();
    let mut answer: usize = 0;
    for (key, val) in map.iter() {
        if *val {
            answer += 1;
            current.insert(*key);
        }
    }
    println!("Day 0: {}", answer);
    let dirs: Vec<(i64, i64)> = vec![(-1, -1), (-1, 1), (1, -1), (1, 1), (2, 0), (-2, 0)];
    for day in 1..101 {
        let mut new: HashSet<(i64, i64)> = HashSet::new();
        // println!("config = [");
        // for pos in &current {
        //     println!("\t({} {})", pos.0, pos.1);
        // }
        // println!("]");
        let mut positions: HashSet<(i64, i64)> = HashSet::new();
        for pos in &current {
            positions.insert(pos.clone());
            for dir in &dirs {
                let new_pos = (pos.0 + dir.0, pos.1 + dir.1);
                positions.insert(new_pos);
            }
        }
        for pos in &positions {
            let mut flipped = 0;
            for dir in &dirs {
                let new_pos = (pos.0 + dir.0, pos.1 + dir.1);
                if current.contains(&new_pos) {
                    flipped += 1;
                }
            }
            let is_flipped = current.contains(&pos);
            if is_flipped {
                if flipped > 0 && flipped < 3 {
                    new.insert(*pos);
                }
            } else {
                if flipped == 2 {
                    new.insert(*pos);
                }
            }
        }
        let mut answer: usize = 0;
        for _ in &new {
            answer += 1;
        }
        println!("Day {}: {}", day, answer);
        current = new.clone();
    }
}
