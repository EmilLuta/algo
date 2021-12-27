use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashSet};
use std::env;
use std::fs;

fn valid(n_r: i8, n_c: i8, n: usize, m: usize) -> bool {
    0 <= n_r && n_r < (n as i8) && 0 <= n_c && n_c < (m as i8)
}

fn dfs(
    map: &Vec<Vec<u8>>,
    seen: &mut HashSet<(usize, usize)>,
    r: usize,
    c: usize,
    n: usize,
    m: usize,
) -> i64 {
    seen.insert((r, c));
    let mut answer = 1;
    let dirs: Vec<(i8, i8)> = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];
    for d in &dirs {
        let n_r = r as i8 + d.0;
        let n_c = c as i8 + d.1;
        if valid(n_r, n_c, n, m) {
            let n_r = n_r as usize;
            let n_c = n_c as usize;
            if !seen.contains(&(n_r as usize, n_c as usize)) && map[n_r][n_c] != 9 {
                answer += dfs(map, seen, n_r, n_c, n, m);
            }
        }
    }
    answer
}

fn main() {
    const RADIX: u32 = 10;
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let n = lines.len();
    let m = lines[0].len();
    let mut map: Vec<Vec<u8>> = vec![vec![0; m]; n];
    for r in 0..n {
        for (c, d) in lines[r].chars().enumerate() {
            map[r][c] = d.to_digit(RADIX).unwrap() as u8;
        }
    }
    let mut answer: i64 = 1;
    let mut seen: HashSet<(usize, usize)> = HashSet::new();
    let mut heap: BinaryHeap<Reverse<i64>> = BinaryHeap::new();
    for r in 0..n {
        for c in 0..m {
            if !seen.contains(&(r, c)) && map[r][c] != 9 {
                let size = Reverse(dfs(&map, &mut seen, r, c, n, m));
                if heap.len() == 3 {
                    if size < *heap.peek().unwrap() {
                        heap.pop();
                        heap.push(size);
                    }
                    continue;
                }
                heap.push(size);
            }
        }
    }
    for val in &heap {
        answer *= val.0;
    }

    println!("answer = {}", answer);
}
