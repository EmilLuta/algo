use std::cmp::max;
use std::env;
use std::fs;
use std::mem::swap;

#[derive(Debug)]
struct Entry {
    r: usize,
    c: usize,
}

fn parse_entry(entry: String) -> Entry {
    let mut it = entry.split(",");
    let c: usize = it.next().unwrap().parse().unwrap();
    let r: usize = it.next().unwrap().parse().unwrap();
    Entry { r, c }
}

fn parse_line(line: String) -> (Entry, Entry) {
    let mut it = line.split(" -> ");
    let a: String = it.next().unwrap().to_string();
    let entry_a = parse_entry(a);
    let b = it.next().unwrap().to_string();
    let entry_b = parse_entry(b);
    (entry_a, entry_b)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|s| s.to_string())
        .collect();
    let mut points: Vec<(Entry, Entry)> = vec![];
    let mut max_r = 0;
    let mut max_c = 0;
    for line in &lines {
        let (start, end) = parse_line(line.clone());
        max_r = max(max_r, max(start.r, end.r));
        max_c = max(max_c, max(start.c, end.c));
        points.push((start, end));
    }
    let n = max_r + 1;
    let m = max_c + 1;
    let mut map: Vec<Vec<usize>> = vec![vec![0; m]; n];
    for seg in &points {
        if seg.0.r == seg.1.r {
            let mut low = seg.0.c;
            let mut high = seg.1.c;
            if low > high {
                swap(&mut low, &mut high);
            }
            for c in low..high + 1 {
                map[seg.0.r][c] += 1;
            }
            continue;
        }
        if seg.0.c == seg.1.c {
            let mut low = seg.0.r;
            let mut high = seg.1.r;
            if low > high {
                swap(&mut low, &mut high);
            }
            for r in low..high + 1 {
                map[r][seg.0.c] += 1;
            }
            continue;
        }
        let r_increasing = seg.0.r < seg.1.r;
        let c_increasing = seg.0.c < seg.1.c;
        let mut curr_r = seg.0.r;
        let mut curr_c = seg.0.c;
        map[seg.1.r][seg.1.c] += 1;
        while curr_r != seg.1.r && curr_c != seg.1.c {
            map[curr_r][curr_c] += 1;
            if r_increasing {
                curr_r += 1;
            } else {
                curr_r -= 1;
            }
            if c_increasing {
                curr_c += 1;
            } else {
                curr_c -= 1;
            }
        }
    }
    let mut answer = 0;
    for r in 0..n {
        for c in 0..m {
            if map[r][c] > 1 {
                answer += 1;
            }
        }
    }
    println!("answer = {}", answer);
    // for r in 0..n {
    //     for c in 0..m {
    //         print!("{}", map[r][c]);
    //     }
    //     println!("");
    // }
    // println!("{:?}", points);
}
