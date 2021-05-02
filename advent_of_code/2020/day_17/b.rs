use std::{env, fs};

fn is_ok(n_x: i32, n_y: i32, n_z: i32, n_w: i32, x: i32, y: i32, z: i32, w: i32) -> bool {
    0 <= x && x < n_x && 0 <= y && y < n_y && 0 <= z && z < n_z && 0 <= w && w < n_w
}

fn count_active(a: &Vec<Vec<Vec<Vec<char>>>>, x: i32, y: i32, z: i32, w: i32) -> i32 {
    let mut answer = 0;
    for w_d in -1..2 {
        for z_d in -1..2 {
            for y_d in -1..2 {
                for x_d in -1..2 {
                    if x_d == 0 && y_d == 0 && z_d == 0 && w_d == 0 {
                        continue;
                    }
                    let xx = x + x_d;
                    let yy = y + y_d;
                    let zz = z + z_d;
                    let ww = w + w_d;
                    if is_ok(
                        a[0][0][0].len() as i32,
                        a[0][0].len() as i32,
                        a[0].len() as i32,
                        a.len() as i32,
                        xx,
                        yy,
                        zz,
                        ww,
                    ) {
                        let x = xx as usize;
                        let y = yy as usize;
                        let z = zz as usize;
                        let w = ww as usize;
                        if a[w][z][y][x] == '#' {
                            answer += 1;
                        }
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
    let mut n_w: usize = 1;
    let mut a: Vec<Vec<Vec<Vec<char>>>> = vec![vec![vec![vec!['.'; n_x]; n_y]; n_z]; n_w];
    for w in 0..n_w {
        for z in 0..n_z {
            for y in 0..n_y {
                for x in 0..n_x {
                    a[w][z][y][x] = lines[y].as_bytes()[x] as char;
                }
            }
        }
    }
    for cycle in 1..7 {
        n_w += 2;
        n_z += 2;
        n_x += 2;
        n_y += 2;
        let mut b: Vec<Vec<Vec<Vec<char>>>> = vec![vec![vec![vec!['.'; n_x]; n_y]; n_z]; n_w];
        for w in 0..n_w {
            for z in 0..n_z {
                for y in 0..n_y {
                    for x in 0..n_x {
                        let a_x = x as i32 - 1;
                        let a_y = y as i32 - 1;
                        let a_z = z as i32 - 1;
                        let a_w = w as i32 - 1;
                        let active = count_active(&a, a_x, a_y, a_z, a_w);
                        if is_ok(
                            a[0][0][0].len() as i32,
                            a[0][0].len() as i32,
                            a[0].len() as i32,
                            a.len() as i32,
                            a_x,
                            a_y,
                            a_z,
                            a_w,
                        ) && a[a_w as usize][a_z as usize][a_y as usize][a_x as usize] == '#'
                        {
                            if active == 2 || active == 3 {
                                b[w][z][y][x] = '#';
                            } else {
                                b[w][z][y][x] = '.';
                            }
                        } else {
                            if active == 3 {
                                b[w][z][y][x] = '#';
                            } else {
                                b[w][z][y][x] = '.';
                            }
                        }
                    }
                }
            }
        }
        a = b;
        // println!("cycle = {}", cycle);
        // for z in 0..n_z {
        //     println!("z = {}", z);
        //     for y in 0..n_y {
        //         for x in 0..n_x {
        //             print!("{}", a[z][y][x]);
        //         }
        //         print!("\n");
        //     }
        //     print!("\n");
        // }
    }
    let mut answer = 0;
    for w in 0..n_w {
        for z in 0..n_z {
            for y in 0..n_y {
                for x in 0..n_x {
                    if a[w][z][y][x] == '#' {
                        answer += 1;
                    }
                }
            }
        }
    }
    println!("{}", answer);
}
