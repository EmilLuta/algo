use std::collections::BTreeMap;
use std::{env, fs, io, thread, time};

fn parse_mask(mask_data: String) -> String {
    let mask_splits: Vec<String> = mask_data.split(" = ").map(|x| x.to_string()).collect();
    let mask = mask_splits[1].clone();
    mask
}

fn parse_mem_change(command: String) -> (i64, i64) {
    let command_value: Vec<String> = command.split(" = ").map(|line| line.to_string()).collect();
    let value = command_value[1].parse::<i64>().unwrap();
    let command = command.as_bytes();
    let n = command.len();
    let mut add = false;
    let mut address: i64 = 0;
    for i in 0..n {
        if command[i] as char == '[' {
            add = true;
            continue;
        } else if command[i] as char == ']' {
            break;
        }
        if add {
            address = address * 10 + (command[i] as char).to_digit(10).unwrap() as i64;
        }
    }
    (address, value)
}

fn get_after_mask(addr: i64, mask: String) -> Vec<i64> {
    let mut bin: String = format!("{:b}", addr);
    let n = mask.as_bytes().len();
    if bin.as_bytes().len() < n {
        bin = (0..n - bin.as_bytes().len())
            .map(|_| "0")
            .collect::<String>()
            + &bin;
    }
    // println!("for mask = {} we got:", mask);
    let mask = mask.as_bytes();
    let bin = bin.as_bytes();
    let mut addrs: Vec<String> = vec!["".to_string()];
    for i in 0..n {
        // thread::sleep(time::Duration::from_millis(1000));
        for j in 0..addrs.len() {
            if mask[i] as char == 'X' {
                let mut new_addr = addrs[j].clone();
                addrs[j].push('0');
                new_addr.push('1');
                addrs.push(new_addr);
            } else if mask[i] as char == '1' {
                addrs[j].push(mask[i] as char);
            } else {
                addrs[j].push(bin[i] as char);
            }
        }
        // println!("for i = {}, addrs = {:#?}", i, addrs);
        // let mut input_text = String::new();
        // io::stdin().read_line(&mut input_text).unwrap();
    }
    let mut out: Vec<i64> = vec![];
    for i in 0..addrs.len() {
        let mut x: i64 = 0;
        for j in 0..n {
            x = x * 2;
            if addrs[i].as_bytes()[j] as char == '1' {
                x += 1;
            }
        }
        out.push(x);
    }
    out
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let commands: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let n = commands.len();
    let mut mem: BTreeMap<i64, i64> = BTreeMap::new();
    let mut mask: String = String::new();
    for i in 0..n {
        if &commands[i][..4] == "mask" {
            mask = parse_mask(commands[i].clone());
        } else {
            let (unmasked_addr, val) = parse_mem_change(commands[i].clone());
            let addrs = get_after_mask(unmasked_addr, mask.clone());
            for addr in addrs {
                mem.insert(addr, val);
            }
        }
    }
    let mut answer: i64 = 0;
    for value in mem.values() {
        answer += value;
    }
    println!("{}", answer);
}
