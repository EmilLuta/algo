use std::collections::BTreeSet;
use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n\n")
        .map(|line| line.to_string())
        .collect();
    let mut answer: i32 = 0;
    for line in lines {
        let mut s: BTreeSet<char> = BTreeSet::new();
        for l in 'a' as u8..'z' as u8 + 1 {
            s.insert(l as char);
        }
        for person in line.split("\n") {
            if person.is_empty() {
                continue;
            }
            let mut curr: BTreeSet<char> = BTreeSet::new();
            for b in person.as_bytes() {
                let c: char = *b as char;
                curr.insert(c);
            }
            let mut n: BTreeSet<char> = BTreeSet::new();
            for c in curr.iter() {
                if let Some(found) = s.take(c) {
                    n.insert(found);
                }
            }
            s = n;
        }
        answer += s.len() as i32;
    }
    println!("{:#?}", answer);
}
