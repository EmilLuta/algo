use std::collections::hash_map::DefaultHasher;
use std::collections::{HashSet, VecDeque};
use std::hash::{Hash, Hasher};
use std::{env, fs};

fn get_players(lines: Vec<String>) -> (VecDeque<i64>, VecDeque<i64>) {
    let mut a: VecDeque<i64> = VecDeque::new();
    let mut b: VecDeque<i64> = VecDeque::new();
    let mut to_a: bool = false;
    for line in lines {
        if line.starts_with("Player") {
            to_a = !to_a;
            continue;
        }
        if line.len() == 0 {
            continue;
        }
        let val: i64 = line.parse().unwrap();
        if to_a {
            a.push_back(val);
        } else {
            b.push_back(val);
        }
    }
    (a, b)
}

fn get_hash(a: VecDeque<i64>, b: VecDeque<i64>) -> u64 {
    let mut hasher_a = DefaultHasher::new();
    a.hash(&mut hasher_a);
    let hash_a = hasher_a.finish();
    let mut hasher_b = DefaultHasher::new();
    b.hash(&mut hasher_b);
    let hash_b = hasher_b.finish();

    let mut hasher = DefaultHasher::new();
    ((hash_a, hash_b)).hash(&mut hasher);
    hasher.finish()
}

fn play(mut a: VecDeque<i64>, mut b: VecDeque<i64>, game_no: i64) -> bool {
    let mut seen = HashSet::new();
    while a.len() > 0 && b.len() > 0 {
        print!("Player 1's deck: ");
        for x in &a {
            print!("{:#?}, ", x);
        }
        println!("");
        print!("Player 2's deck: ");
        for x in &b {
            print!("{:#?}, ", x);
        }
        println!("");
        let hash = get_hash(a.clone(), b.clone());
        let player_a = a.pop_front().unwrap();
        let player_b = b.pop_front().unwrap();
        if seen.contains(&hash) {
            a.push_back(player_a);
            a.push_back(player_b);
        } else {
            seen.insert(hash);
            if player_a <= a.len() as i64 && player_b <= b.len() as i64 {
                let mut new_a = a.clone();
                let mut new_b = b.clone();
                while new_a.len() > player_a as usize {
                    new_a.pop_back();
                }
                while new_b.len() > player_b as usize {
                    new_b.pop_back();
                }
                let answer: bool = play(new_a, new_b, game_no + 1);
                if answer {
                    a.push_back(player_a);
                    a.push_back(player_b);
                } else {
                    b.push_back(player_b);
                    b.push_back(player_a);
                }
            } else {
                if player_a > player_b {
                    a.push_back(player_a);
                    a.push_back(player_b);
                } else if player_a < player_b {
                    b.push_back(player_b);
                    b.push_back(player_a);
                } else {
                    panic!("ai de plm!");
                }
            }
        }
    }
    if game_no != 1 {
        return a.len() != 0;
    }
    let mut answer: i64 = 0;
    let arr: VecDeque<i64>;
    println!("a = {:#?}", a);
    println!("b = {:#?}", b);
    if a.len() < b.len() {
        arr = b;
    } else {
        arr = a;
    }
    let n = arr.len();
    for i in 0..n {
        println!("+ {:#?} * {:#?}", i + 1, arr[n - i - 1]);
        answer += ((i + 1) as i64) * arr[n - i - 1];
    }
    println!("answer = {:#?}", answer);
    return true;
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| l.to_string())
        .collect();
    let (a, b): (VecDeque<i64>, VecDeque<i64>) = get_players(lines);
    play(a, b, 1);
}
