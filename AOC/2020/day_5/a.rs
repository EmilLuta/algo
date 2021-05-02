use std::env;
use std::fs;

fn binary_search(s: &[u8], mut low: usize, mut high: usize, left: char) -> usize {
    let n = s.len();
    for i in 0..n {
        let mid = (high + low) / 2;
        if s[i] as char == left {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    low
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let values: Vec<i32> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .map(|line| {
            let n = line.len();
            let row = binary_search(&line.as_bytes()[0..n - 3], 0, 127, 'F');
            let col = binary_search(&line.as_bytes()[n - 3..n], 0, 7, 'L');
            (row * 8 + col) as i32
        }).collect();
    let mut exists: Vec<bool> = vec![false; 1024];
    for no in values {
        exists[no as usize] = true;
    }
    let mut i: usize = 0;
    loop {
        if exists[i] == true {
            break;
        }
        i += 1;
    }
    loop {
        if exists[i] == false {
            println!("{}", i);
            break;
        }
        i += 1;
    }
}
