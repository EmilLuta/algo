#![feature(map_first_last)]

use std::collections::{BTreeSet, HashSet};
use std::env;
use std::fs;

struct Map {
    matrix: Vec<Vec<u8>>,
    n: usize,
    m: usize,
}

impl Map {
    fn new(data: Vec<String>) -> Map {
        let n = data.len();
        let m = data[0].len();
        const RADIX: u32 = 10;
        let mut matrix: Vec<Vec<u8>> = vec![vec![0; m]; n];
        for r in 0..n {
            let chars: Vec<char> = data[r].chars().collect();
            for c in 0..m {
                matrix[r][c] = chars[c].to_digit(RADIX).unwrap() as u8;
            }
        }
        Map { matrix, n, m }
    }

    fn valid(&self, r: i64, c: i64) -> bool {
        0 <= r && r < self.n as i64 && 0 <= c && c < self.m as i64
    }

    fn shortest_path(&self) -> i64 {
        let mut queue: BTreeSet<(i64, usize, usize)> = BTreeSet::new();
        let mut seen: HashSet<(i64, i64)> = HashSet::new();
        queue.insert((0, 0, 0));
        seen.insert((0, 0));
        let dirs: Vec<(i64, i64)> = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];
        loop {
            let entry = queue.pop_first().unwrap();
            for dir in &dirs {
                let r = entry.1 as i64 + dir.0;
                let c = entry.2 as i64 + dir.1;
                if self.valid(r, c) && !seen.contains(&(r, c)) {
                    seen.insert((r, c));
                    let r = r as usize;
                    let c = c as usize;
                    let dist = entry.0 + self.matrix[r as usize][c as usize] as i64;
                    if r == self.n - 1 && c == self.m - 1 {
                        return dist;
                    }
                    queue.insert((dist, r, c));
                }
            }
        }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let map = Map::new(lines);
    println!("answer = {}", map.shortest_path());
}
