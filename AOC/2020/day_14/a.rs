use std::collections::BTreeMap;
use std::{env, fs};

fn parse_mask(mask_data: String) -> String {
    let mask_splits: Vec<String> = mask_data.split(" = ").map(|x| x.to_string()).collect();
    let mask = mask_splits[1].clone();
    mask
}

fn parse_mem_change(command: String) -> (i32, i64) {
    let command_value: Vec<String> = command.split(" = ").map(|line| line.to_string()).collect();
    let value = command_value[1].parse::<i64>().unwrap();
    let command = command.as_bytes();
    let n = command.len();
    let mut add = false;
    let mut address: i32 = 0;
    for i in 0..n {
        if command[i] as char == '[' {
            add = true;
            continue;
        } else if command[i] as char == ']' {
            break;
        }
        if add {
            address = address * 10 + (command[i] as char).to_digit(10).unwrap() as i32;
        }
    }
    (address, value)
}

fn compute(val: i64, mask: String) -> i64 {
    let mut out_bin: String = String::new();
    let mut bin: String = format!("{:b}", val);
    let n = mask.as_bytes().len();
    if bin.as_bytes().len() < n {
        bin = (0..n - bin.as_bytes().len()).map(|_| "0").collect::<String>() + &bin;
    }
    let mask = mask.as_bytes();
    let bin = bin.as_bytes();
    for i in 0..n {
        if mask[i] as char == 'X' {
            out_bin.push(bin[i] as char);
        } else {
            out_bin.push(mask[i] as char);
        }
    }
    let mut out: i64 = 0;
    for i in 0..n {
        out = out * 2;
        if out_bin.as_bytes()[i] as char == '1' {
            out += 1;
        }
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
    let mut mem: BTreeMap<i32, i64> = BTreeMap::new();
    let mut mask: String = String::new();
    for i in 0..n {
        if &commands[i][..4] == "mask" {
            mask = parse_mask(commands[i].clone());
        } else {
            let (addr, val) = parse_mem_change(commands[i].clone());
            let result = compute(val, mask.clone());
            mem.insert(addr, result);
        }
    }
    let mut answer: i64 = 0;
    for value in mem.values() {
        answer += value;
    }
    println!("{}", answer);
}
