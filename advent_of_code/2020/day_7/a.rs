use std::collections::btree_map::Entry;
use std::collections::BTreeMap;
use std::env;
use std::fs;
use std::str::from_utf8;

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n")
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let mut graph: BTreeMap<String, Vec<(String, i32)>> = BTreeMap::new();
    for line in &lines {
        let data: Vec<String> = line
            .split(" bags contain ")
            .map(|token| token.to_string())
            .collect();
        for item in data[1].split(", ") {
            let bytes = item.as_bytes();
            let mut i: usize = 0;
            let mut quantity: i32 = 0;
            loop {
                if '0' <= bytes[i] as char && bytes[i] as char <= '9' {
                    quantity = quantity * 10 + bytes[i] as i32 - '0' as i32;
                } else {
                    break;
                }
                i += 1;
            }
            i += 1;
            let mut j: usize = bytes.len() - 1;
            loop {
                if bytes[j] as char == 'b' {
                    break;
                }
                j -= 1;
            }
            j -= 1;
            let val: String = String::from(from_utf8(&bytes[i..j]).unwrap());
            if &val == "o other" {
                continue;
            }
            match graph.entry(data[0].clone()) {
                Entry::Vacant(e) => {
                    e.insert(vec![(val, quantity)]);
                }
                Entry::Occupied(mut e) => {
                    e.get_mut().push((val, quantity));
                }
            }
        }
    }
    let mut answer = 0;
    for entry in graph.iter() {
        if entry.0 == "shiny gold" {
            continue;
        }
        let mut q = vec![entry.0];
        let mut index: usize = 0;
        while q.len() > index {
            let node = q[index];
            index += 1;
            let mut found: bool = false;
            if let Some(directions) = graph.get(node) {
                for direction in directions {
                    if direction.0 == "shiny gold" {
                        answer += 1;
                        found = true;
                        break;
                    }
                    q.push(&direction.0);
                }
            }
            if found {
                break;
            }
        }
    }
    println!("{:#?}", answer);
}
