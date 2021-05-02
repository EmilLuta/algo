use std::collections::HashMap;
use std::{env, fs};

fn get_id(line: &String) -> i64 {
    let mut i: usize = 0;
    let n: usize = line.len();
    while !('0' <= line.as_bytes()[i] as char && line.as_bytes()[i] as char <= '9') {
        i += 1;
    }
    line[i..n - 1].to_string().parse::<i64>().unwrap()
}

fn get_tiles(lines: &Vec<String>) -> HashMap<i64, Vec<Vec<char>>> {
    let n = lines.len();
    assert!(n % 12 == 0);
    let mut i: usize = 0;
    let mut tiles: HashMap<i64, Vec<Vec<char>>> = HashMap::new();
    while i < n {
        let id: i64 = get_id(&lines[i]);
        let mut tile: Vec<Vec<char>> = vec![];
        for x in i + 1..i + 11 {
            tile.push(lines[x].chars().collect());
        }
        tiles.insert(id, tile);
        i += 12;
    }
    tiles
}

fn get_sides(a: &Vec<Vec<char>>) -> Vec<Vec<char>> {
    let n = a.len();
    const FIRST_ROW_FW: usize = 0;
    const FIRST_ROW_BW: usize = 1;
    const LAST_ROW_FW: usize = 2;
    const LAST_ROW_BW: usize = 3;
    const FIRST_COL_FW: usize = 4;
    const FIRST_COL_BW: usize = 5;
    const LAST_COL_FW: usize = 6;
    const LAST_COL_BW: usize = 7;
    let mut sides: Vec<Vec<char>> = vec![vec!['E'; n]; 8];
    for i in 0..n {
        sides[FIRST_ROW_FW][i] = a[0][i];
        sides[FIRST_ROW_BW][n - i - 1] = a[0][i];
        sides[LAST_ROW_FW][i] = a[n - 1][i];
        sides[LAST_ROW_BW][n - i - 1] = a[n - 1][i];
        sides[FIRST_COL_FW][i] = a[i][0];
        sides[FIRST_COL_BW][n - i - 1] = a[i][0];
        sides[LAST_COL_FW][i] = a[i][n - 1];
        sides[LAST_COL_BW][n - i - 1] = a[i][n - 1];
    }
    sides
}

fn tiles_fit(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let a_sides = get_sides(a);
    let b_sides = get_sides(b);
    for a in &a_sides {
        for b in &b_sides {
            let n: usize = b.len();
            let mut ok = true;
            for i in 0..n {
                if a[i] != b[i] {
                    ok = false;
                }
            }
            if ok {
                return ok;
            }
        }
    }
    false
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let tiles: HashMap<i64, Vec<Vec<char>>> = get_tiles(&lines);
    let mut tile_degree: HashMap<i64, usize> = HashMap::new();
    for (id, tile) in &tiles {
        for (match_id, match_tile) in &tiles {
            if match_id == id {
                continue;
            }
            if tiles_fit(tile, match_tile) {
                let count = tile_degree.entry(*id).or_insert(0);
                *count += 1;
            }
        }
    }
    let mut answer: i64 = 1;
    for (id, degree) in &tile_degree {
        if *degree == 2 {
            answer *= id;
        }
    }
    println!("{:#?}", tile_degree);
    println!("{:#?}", answer);
}
