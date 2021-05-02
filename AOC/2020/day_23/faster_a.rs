use std::{env, fs};

fn get_next_label(to_add_at: usize, max: usize) -> usize {
    if to_add_at <= 1 {
        max
    } else {
        to_add_at - 1
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let a: Vec<usize> = lines[0]
        .chars()
        .map(|c| c.to_digit(10).unwrap() as usize)
        .collect();
    let n: usize = a.len();
    let mut ll: Vec<usize> = vec![0; n + 1];
    let max: usize = *a.iter().max().unwrap();
    for i in 1..a.len() {
        ll[a[i - 1]] = a[i];
    }
    ll[a[n - 1]] = a[0];
    let steps = 100;
    let mut label = a[0];
    for _ in 0..steps {
        let mut to_be_switched: Vec<usize> = vec![];
        let mut current_label: usize = label;
        for _ in 0..3 {
            to_be_switched.push(ll[current_label]);
            current_label = ll[current_label];
        }
        ll[label] = ll[current_label];
        for i in 0..3 {
            ll[to_be_switched[i]] = 0;
        }
        let mut to_add_at = get_next_label(label, max);
        while to_be_switched.iter().any(|&e| e == to_add_at) {
            to_add_at = get_next_label(to_add_at, max);
        }
        let temp = ll[to_add_at];
        for i in 0..3 {
            ll[to_add_at] = to_be_switched[i];
            to_add_at = ll[to_add_at];
        }
        ll[to_add_at] = temp;
        label = ll[label];
    }
    let mut answer: String = String::new();
    let mut label = 1;
    while ll[label] != 1 {
        let s = ll[label].to_string();
        answer += &s;
        label = ll[label];
    }
    println!("answer = {:#?}", answer);
}
