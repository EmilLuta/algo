use std::env;
use std::fs;

fn ok(r: i32, c: i32, n: usize, m: usize) -> bool {
    0 <= r && r < n as i32 && 0 <= c && c < m as i32
}

fn count(a: &Vec<Vec<i32>>, r: usize, c: usize) -> usize {
    let n: usize = a.len();
    let m: usize = a[0].len();
    let dirs: Vec<(i32, i32)> = vec![
        (1, 1),
        (1, -1),
        (-1, -1),
        (-1, 1),
        (1, 0),
        (-1, 0),
        (0, 1),
        (0, -1),
    ];
    let mut count: usize = 0;
    for dir in dirs {
        let n_r: i32 = r as i32 + dir.0;
        let n_c: i32 = c as i32 + dir.1;
        if ok(n_r, n_c, n, m) && a[n_r as usize][n_c as usize] % 10 == 1 {
            count += 1;
        }
    }
    count
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let input: Vec<Vec<char>> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string().chars().collect())
        .collect();
    let n: usize = input.len();
    let m: usize = input[0].len();
    let mut a: Vec<Vec<i32>> = vec![vec![0; m]; n];
    for r in 0..n {
        for c in 0..m {
            if input[r][c] == '.' {
                a[r][c] = 2;
            }
        }
    }
    let mut changes: bool = true;
    let mut change_no: i32 = 0;
    while changes {
        change_no += 1;
        changes = false;
        for r in 0..n {
            for c in 0..m {
                let count: usize = count(&a, r, c);
                if a[r][c] % 10 == 0 && count == 0 {
                    a[r][c] += 10;
                    changes = true;
                } else if a[r][c] % 10 == 1 {
                    if count > 3 {
                        changes = true;
                    } else {
                        a[r][c] += 10;
                    }
                }
            }
        }
        for r in 0..n {
            for c in 0..m {
                if a[r][c] != 2 {
                    a[r][c] /= 10;
                }
            }
        }
    }
    let mut answer: i32 = 0;
    for r in 0..n {
        for c in 0..m {
            if a[r][c] % 10 == 1 {
                answer += 1;
            }
        }
    }
    println!(
        "we had {:#?} changes and the answer is {:#?}",
        change_no, answer
    );
}
