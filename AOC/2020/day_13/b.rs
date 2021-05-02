use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let buses: Vec<i64> = lines[1]
        .split(",")
        .map(|line| {
            if line.as_bytes()[0] as char == 'x' {
                1
            } else {
                line.parse().unwrap()
            }
        })
        .collect();
    let mut max = i64::MIN;
    let mut index: usize = 0;
    for i in 0..buses.len() {
        if buses[i] > max {
            max = buses[i];
            index = i;
        }
    }
    let mut i = 100000000000000 / buses[index];
    // let mut i = 1;
    while i64::MAX - buses[index] * i > buses[index] {
        let target = buses[index] * i;
        let mut ok = true;
        for j in 0..index {
            if (target - (index - j) as i64) % buses[j] != 0 {
                ok = false;
                break;
            }
        }
        if ok {
            for j in index + 1..buses.len() {
                if (target + (j - index) as i64) % buses[j] != 0 {
                    ok = false;
                    break;
                }
            }
        }
        if ok {
            println!("{}", target);
            return;
        }
        i += 1;
    }
}
