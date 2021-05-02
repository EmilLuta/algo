use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let input: Vec<i64> = lines[1]
        .split(",")
        .map(|line| {
            if line.as_bytes()[0] as char == 'x' {
                -1
            } else {
                line.parse().unwrap()
            }
        })
        .collect();
    let mut buses: Vec<(i64, usize)> = vec![];
    for i in 0..input.len() {
        if input[i] != -1 {
            buses.push((input[i], i));
        }
    }
    buses.sort_by(|x, y| y.cmp(x));
    let mut target: i64 = buses[0].0 - buses[0].1 as i64;
    let mut p: i64 = buses[0].0;
    for i in 1..buses.len() {
        while (target + buses[i].1 as i64) % buses[i].0 != 0 {
            target += p;
        }
        p *= buses[i].0;
    }
    println!("{:#?}", target);
}
