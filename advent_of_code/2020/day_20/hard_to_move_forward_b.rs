use std::collections::HashMap;
use std::{env, fs, thread, time};

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

fn flip(image: &Vec<Vec<char>>) -> Vec<Vec<char>> {
    let n = image.len();
    let mut new_image: Vec<Vec<char>> = vec![vec!['.'; n]; n];
    for r in 0..n {
        for c in 0..n {
            new_image[r][n - c - 1] = image[r][c];
        }
    }
    new_image
}

fn rotate(image: &Vec<Vec<char>>) -> Vec<Vec<char>> {
    let n = image.len();
    let mut new_image: Vec<Vec<char>> = vec![vec!['.'; n]; n];
    for r in 0..n {
        for c in 0..n {
            new_image[c][n - r - 1] = image[r][c];
        }
    }
    new_image
}

fn north(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let mut ok = true;
    let n = a.len();
    for i in 0..n {
        if a[0][i] != b[n - 1][i] {
            ok = false;
        }
    }
    ok
}

fn south(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let mut ok = true;
    let n = a.len();
    for i in 0..n {
        if a[n - 1][i] != b[0][i] {
            ok = false;
        }
    }
    ok
}

fn east(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let mut ok = true;
    let n = a.len();
    for i in 0..n {
        if a[i][0] != b[i][n - 1] {
            ok = false;
        }
    }
    ok
}

fn west(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let mut ok = true;
    let n = a.len();
    for i in 0..n {
        if a[i][n - 1] != b[i][0] {
            ok = false;
        }
    }
    ok
}

fn fitting_on(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> (Vec<Vec<char>>, char) {
    let n = a.len();
    let mut im = b.clone();
    let mut c = 0;
    loop {
        if north(a, &im) {
            return (im, 'N');
        }
        if south(a, &im) {
            return (im, 'S');
        }
        if east(a, &im) {
            return (im, 'E');
        }
        if west(a, &im) {
            return (im, 'W');
        }
        let mut ok = true;
        if c == 3 {
            im = flip(&rotate(&im));
        } else {
            im = rotate(&im);
        }
        c += 1;
    }
}

fn compute_image(
    tiles: &HashMap<i64, Vec<Vec<char>>>,
    tile_degrees: &HashMap<i64, Vec<i64>>,
    n: usize,
    corner: i64,
) {
    // let mut image: Vec<Vec<char>> = vec![vec!['.'; n]; n];
    let mut config: Vec<Vec<i64>> = vec![vec![0; n / 10]; n / 10];
    let mut start = tiles.get(&corner).unwrap().clone();
    let mut c = 0;
    let first = &tile_degrees[&corner][0];
    let second = &tile_degrees[&corner][1];
    while (fitting_on(&start, tiles.get(first).unwrap()).1 != 'E'
        || fitting_on(&start, tiles.get(second).unwrap()).1 != 'S')
        && (fitting_on(&start, tiles.get(first).unwrap()).1 != 'S'
            || fitting_on(&start, tiles.get(second).unwrap()).1 != 'E')
    {
        if c == 3 {
            start = flip(&rotate(&start));
        } else {
            start = rotate(&start);
        }
        c += 1;
    }
    config[0][0] = corner;
    // TODO: Gotta flip them, put in right position and move from there.
    if fitting_on(&start, tiles.get(first).unwrap()).1 == 'E' {}
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let tiles: HashMap<i64, Vec<Vec<char>>> = get_tiles(&lines);
    let mut tile_degree: HashMap<i64, Vec<i64>> = HashMap::new();
    for (id, tile) in &tiles {
        for (match_id, match_tile) in &tiles {
            if match_id == id {
                continue;
            }
            if tiles_fit(tile, match_tile) {
                let all_edges = tile_degree.entry(*id).or_insert(vec![]);
                all_edges.push(*match_id);
            }
        }
    }
    let mut threes = 0;
    let mut twos = 0;
    let mut fours = 0;
    let mut corners: Vec<i64> = vec![];
    for (id, degree) in &tile_degree {
        match degree.len() {
            2 => {
                twos += 1;
                corners.push(*id);
            }
            3 => {
                threes += 1;
            }
            4 => {
                fours += 1;
            }
            _ => {
                panic!("wtf?");
            }
        }
    }
    let n = (twos / 2 + threes / 4) * 10;
    compute_image(&tiles, &tile_degree, n as usize, corners[0]);
}
