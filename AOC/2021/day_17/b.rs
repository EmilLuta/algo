use std::cmp::max;
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
    let x = if x1 > x2 { x1 } else { x2 };
    assert!(y < 0);
    assert!(x > 0);
    let max_y = -y;
    let max_x = x2 + 1;
    let mut answer = 0;
    for x in 0..max_x {
        for y in y1..max_y {
            // println!("{}, {}", x, y);
            let mut x_d = x;
            let mut y_d = y;
            let mut curr_x = 0;
            let mut curr_y = 0;
            while curr_y >= y1 {
                curr_x += x_d;
                curr_y += y_d;
                x_d = max(x_d - 1, 0);
                y_d -= 1;
                // println!("here {}, {}", curr_x, curr_y);
                if x1 <= curr_x && curr_x <= x2 && y1 <= curr_y && curr_y <= y2 {
                    answer += 1;
                    break;
                }
            }
        }
    }

    println!("answer = {}", answer);
}
