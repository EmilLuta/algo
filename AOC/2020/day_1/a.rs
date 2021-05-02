use std::collections::BTreeMap;
use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    const TARGET: i32 = 2020;
    let mut map: BTreeMap<i32, (usize, usize)> = BTreeMap::new();
    let numbers: Vec<i32> = fs::read_to_string(&args[1]).unwrap().lines().map(|line| {
        line.to_string().parse::<i32>().unwrap()
    }).collect();
    let n = numbers.len();
    for i in 0..n {
        for j in i..n {
            map.insert(numbers[i] + numbers[j], (i, j));
        }
    }
    for i in 0..n {
        if let Some(ids) = map.get(&(TARGET - numbers[i])) {
            let (j, k) = ids;
            if *j != i && *k != i {
                println!("{}", numbers[i] * numbers[*j] * numbers[*k]);
                return;
            }
        }
    }
}
