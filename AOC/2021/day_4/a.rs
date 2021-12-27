use std::collections::HashMap;
use std::env;
use std::fs;

#[derive(Debug)]
struct Board {
    board: Vec<Vec<i32>>,
    hash_board: HashMap<i32, (usize, usize)>,
    n: usize,
}

impl Board {
    fn new(board: Vec<Vec<i32>>) -> Board {
        let mut hash_board: HashMap<i32, (usize, usize)> = HashMap::new();
        for r in 0..board.len() {
            for c in 0..board[0].len() {
                hash_board.insert(board[r][c], (r, c));
            }
        }
        let n = board.len();
        Board {
            board,
            hash_board,
            n,
        }
    }

    fn mark(&mut self, val: i32) -> bool {
        if !self.hash_board.contains_key(&val) {
            return false;
        }
        let (r, c) = self.hash_board[&val];
        self.board[r][c] = -1;
        let mut row_good: bool = true;
        for n_c in 0..self.n {
            if self.board[r][n_c] != -1 {
                row_good = false;
            }
        }
        let mut column_good: bool = true;
        for n_r in 0..self.n {
            if self.board[n_r][c] != -1 {
                column_good = false;
            }
        }
        row_good || column_good
    }

    fn get_sum_left(&self) -> i32 {
        let mut answer = 0;
        for r in 0..self.n {
            for c in 0..self.n {
                if self.board[r][c] != -1 {
                    answer += self.board[r][c];
                }
            }
        }
        answer
    }
}

#[derive(Debug)]
struct Data {
    arr: Vec<i32>,
    boards: Vec<Board>,
}

impl Data {
    fn new(raw_input: &Vec<String>) -> Data {
        let arr: Vec<i32> = raw_input[0]
            .split(",")
            .map(|no| i32::from_str_radix(no, 10).unwrap())
            .collect();
        let mut boards: Vec<Board> = vec![];
        for i in (2..raw_input.len()).step_by(6) {
            let mut board: Vec<Vec<i32>> = vec![];
            for j in i..i + 5 {
                board.push(
                    raw_input[j]
                        .split(" ")
                        .filter(|no| !no.is_empty())
                        .map(|no| i32::from_str_radix(no, 10).unwrap())
                        .collect(),
                );
            }
            boards.push(Board::new(board));
        }
        Data { arr, boards }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let mut input = Data::new(&lines);
    for i in 0..input.arr.len() {
        let val = input.arr[i];
        for j in 0..input.boards.len() {
            let winner = input.boards[j].mark(val);
            if winner {
                println!("answer = {}", input.boards[j].get_sum_left() * val);
                return;
            }
        }
    }
}
