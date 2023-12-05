use std::env;
use std::fs;

fn get_start(val: usize) -> usize {
    let val = val as isize;
    std::cmp::max(val - 1, 0) as usize
}

fn get_end(val: usize, limit: usize) -> usize {
    std::cmp::min(val + 2, limit)
}

fn parse(matrix: &[Vec<char>], r: usize, c: usize, n: usize, m: usize) -> (usize, u32) {
    let mut number = 0;
    let mut digit_count = 0;
    for new_c in c..m {
        let curr_val = matrix[r][new_c];
        if curr_val.is_ascii_digit() {
            number *= 10;
            number += curr_val.to_digit(10).unwrap();
            digit_count += 1;
            continue;
        }
        break;
    }
    let c_end = c + digit_count - 1;
    for new_r in get_start(r)..get_end(r, n) {
        for new_c in get_start(c)..get_end(c_end, m) {
            if !matrix[new_r][new_c].is_ascii_digit() && matrix[new_r][new_c] != '.' {
                return (c_end, number);
            }
        }
    }
    (c_end, 0)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let matrix: Vec<Vec<char>> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.chars().collect())
        .collect();
    let n = matrix.len();
    let m = matrix[0].len();
    let mut answer = 0;
    for r in 0..n {
        let mut c = 0;
        while c < m {
            if matrix[r][c].is_ascii_digit() {
                let new_number;
                (c, new_number) = parse(&matrix, r, c, n, m);

                answer += new_number;
            }
            c += 1
        }
    }
    println!("answer = {answer:?}");
}
