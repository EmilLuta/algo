use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let line = &lines[0];
    let mut it = line.split("x=");
    it.next().unwrap();
    let vals = it.next().unwrap();
    let mut it = vals.split(",");
    let xs = it.next().unwrap();
    let y_vals = it.next().unwrap();
    let mut xs = xs.split("..");
    let x1: i64 = xs.next().unwrap().parse().unwrap();
    let x2: i64 = xs.next().unwrap().parse().unwrap();
    let mut ys = y_vals.split("y=");
    ys.next();
    let ys = ys.next().unwrap();
    let mut ys = ys.split("..");
    let y1: i64 = ys.next().unwrap().parse().unwrap();
    let y2: i64 = ys.next().unwrap().parse().unwrap();
    let y = if y1 > y2 { y2 } else { y1 };
    assert!(y < 0);
    let answer = -y * (-y - 1) / 2;
    println!("answer = {}", answer);
}
