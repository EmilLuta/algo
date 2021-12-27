use std::cmp::max;
use std::env;
use std::fs;

#[derive(Debug)]
struct Paper {
    matrix: Vec<Vec<bool>>,
    n: usize,
    m: usize,
    folds: Vec<char>,
}

impl Paper {
    fn new(lines: &Vec<String>) -> Paper {
        let mut n: usize = 0;
        let mut m: usize = 0;
        for line in lines {
            if line.starts_with("f") {
                break;
            }
            let mut it = line.split(",");
            let c = it.next().unwrap().parse::<usize>().unwrap();
            let r = it.next().unwrap().parse::<usize>().unwrap();
            n = max(n, r);
            m = max(m, c);
        }
        n += 1;
        m += 1;
        let mut matrix: Vec<Vec<bool>> = vec![vec![false; m]; n];
        let mut folds: Vec<char> = vec![];
        for line in lines {
            if line.starts_with("f") {
                let mut it = line.split("=");
                let dir = it.next().unwrap();
                if dir.ends_with("x") {
                    folds.push('x');
                }
                if dir.ends_with("y") {
                    folds.push('y');
                }
                continue;
            }
            let mut it = line.split(",");
            let c = it.next().unwrap().parse::<usize>().unwrap();
            let r = it.next().unwrap().parse::<usize>().unwrap();
            matrix[r][c] = true;
        }
        Paper {
            matrix,
            n,
            m,
            folds,
        }
    }

    fn fold_x(&mut self) {
        self.m = self.m / 2;
        for r in 0..self.n {
            for c in 0..self.m {
                self.matrix[r][c] = self.matrix[r][c] || self.matrix[r][2 * self.m - c];
            }
        }
    }

    fn fold_y(&mut self) {
        self.n = self.n / 2;
        for r in 0..self.n {
            for c in 0..self.m {
                self.matrix[r][c] = self.matrix[r][c] || self.matrix[2 * self.n - r][c];
            }
        }
    }

    fn fold(&mut self, i: usize) {
        match self.folds[i] {
            'y' => self.fold_y(),
            'x' => self.fold_x(),
            _ => panic!("Invalid fold\n"),
        }
    }

    fn count(&self) -> i64 {
        let mut answer = 0;
        for r in 0..self.n {
            for c in 0..self.m {
                if self.matrix[r][c] {
                    answer += 1;
                }
            }
        }
        answer
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .filter(|line| !line.is_empty())
        .collect();
    let mut paper = Paper::new(&lines);
    paper.fold(0);
    println!("answer = {}", paper.count());
}
