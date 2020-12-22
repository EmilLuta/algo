use std::{env, fs};

fn is_ok(n_z: i32, n_y: i32, n_x: i32, x: i32, y: i32, z: i32) -> bool {
    if x < 0 {
        return false;
    }
    if y < 0 {
        return false;
    }
    if z < 0 {
        return false;
    }
    0 <= x && x < n_x && 0 <= y && y < n_y && 0 <= z && z < n_z
}

fn count_active(a: &Vec<Vec<Vec<char>>>, x: i32, y: i32, z: i32) -> i32 {
    let mut answer = 0;
    for z_d in -1..2 {
        for y_d in -1..2 {
            for x_d in -1..2 {
                if x_d == 0 && y_d == 0 && y_d == 0 {
                    continue;
                }
                let xx = x + x_d;
                let yy = y + y_d;
                let zz = z + z_d;
                if is_ok(
                    a.len() as i32,
                    a[0].len() as i32,
                    a[0][0].len() as i32,
                    xx,
                    yy,
                    zz,
                ) {
                    let x = xx as usize;
                    let y = yy as usize;
                    let z = zz as usize;
                    if a[z][y][x] == '#' {
                        answer += 1;
                    }
                }
            }
        }
    }
    answer
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let mut n_x: usize = lines.len();
    let mut n_y: usize = n_x;
    let mut n_z: usize = 1;
    let mut a: Vec<Vec<Vec<char>>> = vec![vec![vec!['.'; n_x]; n_y]; n_z];
    for z in 0..n_z {
        println!("z = {}", z);
        for y in 0..n_y {
            for x in 0..n_x {
                a[z][y][x] = lines[y].as_bytes()[x] as char;
                print!("{}", a[z][y][x]);
            }
            print!("\n");
        }
    }
    for cycle in 1..2 {
        //6 + 1 {
        n_z = n_z + 2;
        n_x += 2;
        n_y += 2;
        let mut b: Vec<Vec<Vec<char>>> = vec![vec![vec!['.'; n_x]; n_y]; n_z];
        for z in 0..n_z {
            for y in 0..n_y {
                for x in 0..n_x {
                    let active = count_active(&a, (x - 1) as i32, (y - 1) as i32, (z - 1) as i32);
                    println!("for x = {}, y = {}, z = {}, active = {}", x, y, z, active);
                    if a[z][y][x] == '#' {
                        if active == 2 || active == 3 {
                            b[z + 1][y + 1][x + 1] = '#';
                        } else {
                            b[z + 1][y + 1][x + 1] = '.';
                        }
                    } else {
                        if active == 3 {
                            b[z + 1][y + 1][x + 1] = '#';
                        } else {
                            b[z + 1][y + 1][x + 1] = '.';
                        }
                    }
                }
            }
        }
        a = b;
        println!("cycle = {}", cycle);
        for z in 0..n_z {
            println!("z = {}", z);
            for y in 0..n_y {
                for x in 0..n_x {
                    print!("{}", a[z][y][x]);
                }
                print!("\n");
            }
        }
    }
    let mut answer = 0;
    for z in 0..n_z {
        for y in 0..n_y {
            for x in 0..n_x {
                if a[z][y][x] == '#' {
                    answer += 1;
                }
            }
        }
    }
    println!("{}", answer);
}
