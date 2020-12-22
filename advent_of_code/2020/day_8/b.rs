use std::env;
use std::fs;

fn process_instruction(instruction: &String) -> (String, i32) {
    let op: String = instruction[0..3].to_string();
    let n = instruction.len();
    let val: i32 = instruction[4..n].to_string().parse().unwrap();
    (op, val)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    assert!(args.len() >= 2);
    let mut instructions: Vec<(String, i32)> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| process_instruction(&line.to_string()))
        .collect();
    let n: usize = instructions.len();
    for j in 0..n {
        let mut prev: String = instructions[j].0.clone();
        if &instructions[j].0[..] == "nop" {
            prev = "nop".to_string();
            instructions[j] = ("jmp".to_string(), instructions[j].1);
        } else if &instructions[j].0[..] == "jmp" {
            prev = "jmp".to_string();
            instructions[j] = ("nop".to_string(), instructions[j].1);
        }
        let mut i: i32 = 0;
        let mut acc: i32 = 0;
        let mut seen: Vec<bool> = vec![false; instructions.len()];
        let mut found: bool = true;
        while (i as usize) < n {
            if seen[i as usize] {
                found = false;
                break;
            }
            seen[i as usize] = true;
            match &instructions[i as usize].0[..] {
                "nop" => {
                    i += 1;
                }
                "acc" => {
                    acc += instructions[i as usize].1;
                    i += 1;
                }
                "jmp" => {
                    i += instructions[i as usize].1;
                }
                _ => {
                    println!("olala");
                    assert!(false);
                }
            }
        }
        if found {
            println!("acc = {:#?}", acc);
            break;
        }
        instructions[j] = (prev, instructions[j].1);
    }
}
