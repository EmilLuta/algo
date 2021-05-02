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
    let instructions: Vec<(String, i32)> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| process_instruction(&line.to_string()))
        .collect();
    let mut i: i32 = 0;
    let mut acc: i32 = 0;
    let mut seen: Vec<bool> = vec![false; instructions.len()];
    loop {
        if seen[i as usize] {
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
                assert!(false);
            }
        }
    }
    println!("{:#?}", acc);
}
