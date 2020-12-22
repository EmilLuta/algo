use std::cmp;
use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let a: Vec<i64> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n")
        .filter(|line| !line.is_empty())
        .map(|line| line.parse::<i64>().unwrap())
        .collect();
    let n: usize = a.len();
    let k: usize = args[2].parse().unwrap();
    let mut target: i64 = 0;
    for i in k..n {
        let mut good: bool = false;
        for j in i - k..i {
            for x in j + 1..i {
                if a[j] + a[x] == a[i] {
                    good = true;
                }
            }
        }
        if !good {
            target = a[i];
            break;
        }
    }
    println!("target = {:#?}", target);
    for i in 0..n {
        let mut s: i64 = 0;
        let mut smallest: i64 = std::i64::MAX;
        let mut biggest: i64 = std::i64::MIN;
        for j in i..n {
            s += a[j];
            smallest = cmp::min(smallest, a[j]);
            biggest = cmp::max(biggest, a[j]);
            if s == target {
                println!("{:#?}", smallest + biggest);
            }
        }
    }
}
