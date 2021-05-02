use std::{env, fs};

fn process_instruction(instruction: &String) -> (i32, i32) {
    let op: i32 = match instruction.as_bytes()[0] as char {
        'N' => 0,
        'S' => 180,
        'E' => 90,
        'W' => 270,
        'F' => 1000,
        'L' => 1001,
        'R' => 1002,
        _ => {
            assert!(false);
            -1
        }
    };
    let val: i32 = instruction[1..].to_string().parse().unwrap();
    (op, val)
}

fn run(mut x: i32, mut y: i32, ins: (i32, i32)) -> (i32, i32) {
    println!("{:#?} {:#?} {:#?}", x, y, ins);
    match ins.0 {
        0 => {
            y += ins.1;
        }
        180 => {
            y -= ins.1;
        }
        90 => {
            x += ins.1;
        }
        270 => {
            x -= ins.1;
        }
        _ => {
            assert!(false);
        }
    }
    (x, y)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    assert!(args.len() >= 2);
    let instructions: Vec<(i32, i32)> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| process_instruction(&line.to_string()))
        .collect();
    let mut dir: i32 = 90;
    let mut x: i32 = 0;
    let mut y: i32 = 0;
    for ins in instructions {
        match ins.0 {
            0 | 90 | 180 | 270 => {
                let p = run(x, y, ins);
                x = p.0;
                y = p.1;
            }
            1001 => {
                dir -= ins.1;
                dir += 360;
                dir %= 360;
            }
            1002 => {
                dir += ins.1;
                dir %= 360;
            }
            1000 => {
                let p = run(x, y, (dir, ins.1));
                x = p.0;
                y = p.1;
            }
            _ => {
                assert!(false);
            }
        }
        println!("{} {}", x, y);
    }
}
