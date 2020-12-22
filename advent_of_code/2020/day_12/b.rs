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

fn rotate_right(mut x: i32, mut y: i32) -> (i32, i32) {
    let tmp: i32 = x;
    x = y;
    y = -tmp;
    (x, y)
}

fn rotate_left(mut x: i32, mut y: i32) -> (i32, i32) {
    let tmp: i32 = x;
    x = -y;
    y = tmp;
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
    let mut ship_x: i32 = 0;
    let mut ship_y: i32 = 0;
    let mut waypoint_x: i32 = 10;
    let mut waypoint_y: i32 = 1;
    for ins in instructions {
        match ins.0 {
            0 | 90 | 180 | 270 => {
                let p = run(waypoint_x, waypoint_y, ins);
                waypoint_x = p.0;
                waypoint_y = p.1;
            }
            1001 => {
                let rotations = (ins.1 % 360) / 90;
                let mut p: (i32, i32) = (0, 0);
                for _ in 0..rotations {
                    p = rotate_left(waypoint_x, waypoint_y);
                    waypoint_x = p.0;
                    waypoint_y = p.1;
                }
                waypoint_x = p.0;
                waypoint_y = p.1;
            }
            1002 => {
                let rotations = (ins.1 % 360) / 90;
                let mut p: (i32, i32) = (0, 0);
                for _ in 0..rotations {
                    p = rotate_right(waypoint_x, waypoint_y);
                    waypoint_x = p.0;
                    waypoint_y = p.1;
                }
                waypoint_x = p.0;
                waypoint_y = p.1;
            }
            1000 => {
                ship_x += waypoint_x * ins.1;
                ship_y += waypoint_y * ins.1;
            }
            _ => {
                assert!(false);
            }
        }
        println!(
            "waypoint: ({}, {}), ship: ({}, {})",
            waypoint_x, waypoint_y, ship_x, ship_y
        );
    }
    println!("{}", i32::abs(ship_x) + i32::abs(ship_y));
}
