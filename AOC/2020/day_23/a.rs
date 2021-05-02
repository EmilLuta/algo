use std::{env, fs};

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let mut a: Vec<i64> = lines[0]
        .chars()
        .map(|c| c.to_digit(10).unwrap() as i64)
        .collect();
    let steps = 10_000_000;
    for i in 10..1_000_001 {
        a.push(i);
    }
    let n = a.len();
    let mut curr_pos: usize = 0;
    for m in 0..steps {
        let pivot = a[curr_pos];
        if m % 10000 == 0 {
            println!("-- move {} --", m + 1);
        }
        // print!("cups: ");
        // for i in 0..n {
        //     if i == curr_pos {
        //         print!("({}) ", a[i]);
        //     } else {
        //         print!("{} ", a[i]);
        //     }
        // }
        // println!("");
        let mut val = a[curr_pos] - 1;
        let mut keep: Vec<i64> = vec![];
        // print!("pick up: ");
        for to_remove in 1..4 {
            let index = (curr_pos + to_remove) % n;
            keep.push(a[index]);
            // print!("{} ", a[index]);
        }
        let start = curr_pos + 1;
        let end = curr_pos + 3;
        if end < n {
            a.drain(start..end + 1);
        } else if start == n {
            a.drain((start % n)..(end % n) + 1);
        } else {
            a.drain(start..n);
            a.drain(0..(end % n) + 1);
        }
        // println!("");
        while !a.iter().any(|&x| x == val) {
            if val == 1 {
                val = 1000000;
            } else {
                val -= 1;
            }
        }
        let val_index = a.iter().position(|x| *x == val).unwrap() + 1;
        // println!("destination: {}", val);
        keep.reverse();
        for x in keep {
            a.insert(val_index, x);
        }
        while pivot != a[curr_pos] {
            a.rotate_left(1);
        }
        curr_pos += 1;
        curr_pos %= n;
        // println!("");
    }
    println!("-- final --");
    print!("cups: ");
    for i in 0..n {
        if i == curr_pos {
            print!("({}) ", a[i]);
        } else {
            print!("{} ", a[i]);
        }
    }
    println!("");
}
