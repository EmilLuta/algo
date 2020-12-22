use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let arrival: i32 = lines[0].parse().unwrap();
    let buses: Vec<i32> = lines[1]
        .split(",")
        .filter(|line| line.as_bytes()[0] as char != 'x')
        .map(|line| line.parse().unwrap())
        .collect();
    let mut min_wait = i32::MAX;
    let mut answer = -1;
    for bus in &buses {
        let mut pick_up: i32 = arrival / bus;
        if arrival % bus != 0 {
            pick_up += 1;
        }
        let time_to_wait = pick_up * bus - arrival;
        if time_to_wait < min_wait {
            min_wait = time_to_wait;
            answer = *bus;
        }
    }
    println!("{}", answer * min_wait);
}
