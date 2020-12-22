use std::collections::BTreeSet;
use std::env;
use std::fs;
use std::iter::FromIterator;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut numbers: Vec<i128> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n")
        .filter(|line| !line.is_empty())
        .map(|line| line.parse::<i128>().unwrap())
        .collect();
    numbers.sort();
    let got: BTreeSet<i128> = BTreeSet::from_iter(numbers.iter().cloned());
    let n: usize = numbers.len();
    let max: usize = (numbers[n - 1] as usize) + 1;
    let mut dp: Vec<i128> = vec![0; max];
    dp[0] = 1;
    for i in 1..max {
        if !got.contains(&(i as i128)) {
            continue;
        }
        let mut start: usize = 0;
        if i > 3 {
            start = i - 3;
        }
        for j in start..i {
            dp[i] += dp[j];
        }
    }
    for i in 0..max {
        println!("for i = {}, we got {} ways", i, dp[i]);
    }
}
