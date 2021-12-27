use std::env;
use std::fs;

#[derive(Debug)]
struct Map {
    matrix: Vec<Vec<u8>>,
    n: usize,
    m: usize,
}

impl Map {
    fn new(lines: &Vec<String>) -> Map {
        const RADIX: u32 = 10;
        let mut matrix: Vec<Vec<u8>> = vec![vec![0; 10]; 10];
        let mut r = 0;
        let mut c = 0;
        for line in lines {
            for ch in line.chars() {
                matrix[r][c] = ch.to_digit(RADIX).unwrap() as u8;
                c += 1;
            }
            c = 0;
            r += 1;
        }
        Map {
            matrix,
            n: 10,
            m: 10,
        }
    }

    fn clear(&mut self) -> bool {
        let mut flashed = 0;
        for r in 0..self.n {
            for c in 0..self.m {
                if self.matrix[r][c] > 9 {
                    self.matrix[r][c] = 0;
                    flashed += 1;
                }
            }
        }
        flashed == self.n * self.m
    }

    fn is_valid(&self, r: i8, c: i8) -> bool {
        0 <= r && (r as usize) < self.n && 0 <= c && (c as usize) < self.m
    }

    fn dfs(&mut self, r: usize, c: usize, flashed: &mut Vec<Vec<bool>>) {
        flashed[r][c] = true;
        let mut dirs: Vec<(i8, i8)> = vec![];
        for i in -1..2 {
            for j in -1..2 {
                if i == j && i == 0 {
                    continue;
                }
                dirs.push((i, j));
            }
        }
        for dir in dirs {
            let new_r: i8 = r as i8 + dir.0;
            let new_c: i8 = c as i8 + dir.1;
            if self.is_valid(new_r, new_c) {
                let new_r: usize = new_r as usize;
                let new_c: usize = new_c as usize;
                self.matrix[new_r][new_c] += 1;
                if !flashed[new_r][new_c] && self.matrix[new_r][new_c] > 9 {
                    self.dfs(new_r, new_c, flashed);
                }
            }
        }
    }

    fn light(&mut self) -> bool {
        let mut flashed: Vec<Vec<bool>> = vec![vec![false; self.m]; self.n];
        for r in 0..self.n {
            for c in 0..self.m {
                self.matrix[r][c] += 1;
                if !flashed[r][c] && self.matrix[r][c] > 9 {
                    self.dfs(r, c, &mut flashed);
                }
            }
        }
        self.clear()
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let mut map = Map::new(&lines);
    let mut i = 0;
    let mut synced = false;
    while !synced {
        i += 1;
        synced = map.light();
    }
    println!("answer = {}", i)
}
