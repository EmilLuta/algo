use std::collections::HashMap;
use std::{cmp, env, fs};

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
        if a[i][n - 1] != b[i][0] {
            ok = false;
        }
    }
    ok
}

fn west(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>) -> bool {
    let mut ok = true;
    let n = a.len();
    for i in 0..n {
        if a[i][0] != b[i][n - 1] {
            ok = false;
        }
    }
    ok
}

fn get_start_tile(tiles: &HashMap<i64, Vec<Vec<char>>>) -> i64 {
    for key in tiles.keys() {
        return *key;
    }
    return -1;
}

fn get_image_pos(image: &Vec<Vec<char>>, other_image: &Vec<Vec<char>>) -> (char, Vec<Vec<char>>) {
    let mut c = 0;
    let mut new_image = other_image.clone();
    while c <= 7 {
        if north(image, &new_image) {
            return ('N', new_image);
        }
        if south(image, &new_image) {
            return ('S', new_image);
        }
        if east(image, &new_image) {
            return ('E', new_image);
        }
        if west(image, &new_image) {
            return ('W', new_image);
        }
        if c == 3 {
            new_image = flip(&rotate(&new_image));
        } else {
            new_image = rotate(&new_image);
        }
        c += 1;
    }
    ('-', vec![])
}

fn trim_edges(image: Vec<Vec<char>>) -> Vec<Vec<char>> {
    let mut new_image: Vec<Vec<char>> = vec![vec!['.'; 8]; 8];
    for i in 1..image.len() - 1 {
        for j in 1..image.len() - 1 {
            new_image[i - 1][j - 1] = image[i][j];
        }
    }
    new_image
}

fn convert_map_to_no_tiles(
    map: HashMap<(i32, i32), Vec<Vec<char>>>,
) -> HashMap<(i32, i32), Vec<Vec<char>>> {
    let mut new_map: HashMap<(i32, i32), Vec<Vec<char>>> = HashMap::new();
    for (key, value) in map {
        new_map.insert(key, trim_edges(value.clone()));
    }
    new_map
}

fn is_ok(image: &Vec<Vec<char>>, r: usize, c: usize, n: usize) -> bool {
    if r == 0 {
        return false;
    }
    let config: Vec<(i64, i64)> = vec![
        (0, 0),
        (1, 1),
        (1, 4),
        (0, 5),
        (0, 6),
        (1, 7),
        (1, 10),
        (0, 11),
        (0, 12),
        (1, 13),
        (1, 16),
        (0, 17),
        (0, 18),
        (0, 19),
        (-1, 18),
    ];
    let mut ok = true;
    for x in config {
        let new_r = (r as i64 + x.0) as usize;
        let new_c = (c as i64 + x.1) as usize;
        if !(new_r < n && new_c < n && image[new_r][new_c] == '#') {
            ok = false;
        }
    }
    ok
}

fn mark_monster(mut image: Vec<Vec<char>>, r: usize, c: usize) -> Vec<Vec<char>> {
    let config: Vec<(i64, i64)> = vec![
        (0, 0),
        (1, 1),
        (1, 4),
        (0, 5),
        (0, 6),
        (1, 7),
        (1, 10),
        (0, 11),
        (0, 12),
        (1, 13),
        (1, 16),
        (0, 17),
        (0, 18),
        (0, 19),
        (-1, 18),
    ];
    for x in config {
        let new_r = (r as i64 + x.0) as usize;
        let new_c = (c as i64 + x.1) as usize;
        image[new_r][new_c] = '0';
    }
    image
}

fn mark_monsters(image: Vec<Vec<char>>) -> Vec<Vec<char>> {
    let n: usize = image.len();
    let mut image = image;
    for r in 0..n {
        for c in 0..n {
            if is_ok(&image, r, c, n) {
                image = mark_monster(image, r, c);
            }
        }
    }
    image
}

fn get_answer(image: Vec<Vec<char>>) -> i64 {
    let mut answer: i64 = 0;
    let image = mark_monsters(image);
    for i in 0..image.len() {
        for j in 0..image.len() {
            if image[i][j] == '#' {
                answer += 1;
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
        .map(|l| l.to_string())
        .collect();
    let tiles = get_tiles(&lines);
    let mut map: HashMap<(i32, i32), Vec<Vec<char>>> = HashMap::new();
    let mut positioning: HashMap<i64, (i32, i32)> = HashMap::new();
    let start_id = get_start_tile(&tiles);
    map.insert((0, 0), tiles.get(&start_id).unwrap().to_vec());
    positioning.insert(start_id, (0, 0));
    assert!(start_id != -1);
    let mut queue: Vec<i64> = vec![start_id];
    let mut index = 0;
    while index < queue.len() {
        let id = queue[index];
        index += 1;
        let position = positioning.get(&id).unwrap().clone();
        let image = map.get(&position).unwrap().to_vec();
        for (other_id, other_image) in &tiles {
            if *other_id == id {
                continue;
            }
            let (direction, correct_pos_image) = get_image_pos(&image, other_image);
            match direction {
                'N' => {
                    if !positioning.contains_key(other_id) {
                        queue.push(*other_id);
                    }
                    let new_pos = (position.0, position.1 - 1);
                    map.insert(new_pos, correct_pos_image);
                    positioning.insert(*other_id, new_pos);
                }
                'S' => {
                    if !positioning.contains_key(other_id) {
                        queue.push(*other_id);
                    }
                    let new_pos = (position.0, position.1 + 1);
                    map.insert(new_pos, correct_pos_image);
                    positioning.insert(*other_id, new_pos);
                }
                'W' => {
                    if !positioning.contains_key(other_id) {
                        queue.push(*other_id);
                    }
                    let new_pos = (position.0 - 1, position.1);
                    map.insert(new_pos, correct_pos_image);
                    positioning.insert(*other_id, new_pos);
                }
                'E' => {
                    if !positioning.contains_key(other_id) {
                        queue.push(*other_id);
                    }
                    let new_pos = (position.0 + 1, position.1);
                    map.insert(new_pos, correct_pos_image);
                    positioning.insert(*other_id, new_pos);
                }
                '-' => {}
                _ => {
                    panic!("wtf?");
                }
            }
        }
    }
    let map = convert_map_to_no_tiles(map);
    let n: usize = (tiles.len() as f64).sqrt() as usize;
    let mut full_image: Vec<Vec<char>> = vec![vec![' '; n * 8]; n * 8];
    let mut min_r = 0;
    let mut min_c = 0;
    let mut max_r = 0;
    let mut max_c = 0;
    for (_, value) in &positioning {
        min_r = cmp::min(min_r, value.0);
        max_r = cmp::max(max_r, value.0);
        min_c = cmp::min(min_c, value.1);
        max_c = cmp::max(max_c, value.1);
    }
    for cc in min_c..max_c + 1 {
        for rr in min_r..max_r + 1 {
            let image = map.get(&(rr, cc)).unwrap();
            let r = ((rr + min_r.abs()) * 8) as usize;
            let c = ((cc + min_c.abs()) * 8) as usize;
            let image_n = image.len();
            for i in 0..image_n {
                for j in 0..image_n {
                    full_image[c + i][r + j] = image[i][j];
                }
            }
        }
    }
    println!("sea monsters = {}", get_answer(full_image.clone()));
    for c in 0..8 {
        // println!("full_image = ");
        // for i in 0..full_image.len() {
        //     for j in 0..full_image.len() {
        //         print!("{}", full_image[i][j]);
        //     }
        //     println!("");
        // }
        // println!("");
        if c == 3 {
            full_image = flip(&rotate(&full_image));
        } else {
            full_image = rotate(&full_image);
        }
        println!("sea monsters = {}", get_answer(full_image.clone()));
    }
}
