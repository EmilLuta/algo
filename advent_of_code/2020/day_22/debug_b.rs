use std::collections::{HashSet, VecDeque};
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

fn play(mut a: VecDeque<i64>, mut b: VecDeque<i64>, game_no: i64) -> bool {
    println!("=== Game {} ===\n", game_no);
    let mut seen: HashSet<(i64, i64)> = HashSet::new();
    let mut round: i64 = 1;
    while a.len() > 0 && b.len() > 0 {
        println!("-- Round {} (Game {}) --", round, game_no);
        round += 1;
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
        let player_a = a.pop_front().unwrap();
        let player_b = b.pop_front().unwrap();
        println!("Player 1 plays: {}", player_a);
        println!("Player 2 plays: {}", player_b);
        if seen.contains(&(player_a, player_b)) {
            seen.insert((player_a, player_b));
            a.push_back(player_a);
            a.push_back(player_b);
            println!("Player 1 wins round {} of game {}!", round - 1, game_no);
        } else {
            if player_a <= a.len() as i64 && player_b <= b.len() as i64 {
                println!("Playing a sub-game to determine the winner...\n");
                // println!(
                //     "player a = {}, a size = {}, player b = {}, b size = {}",
                //     player_a,
                //     a.len() + 1,
                //     player_b,
                //     b.len() + 1
                // );
                // println!(
                //     "player_a {} <= {} a.len() as i64 + 1 == {}",
                //     player_a,
                //     a.len() as i64 + 1,
                //     player_a <= a.len() as i64 + 1
                // );
                // println!(
                //     "player_b {} <= {} b.len() as i64 + 1 == {}",
                //     player_b,
                //     b.len() as i64 + 1,
                //     player_b <= b.len() as i64 + 1
                // );
                let mut new_a = a.clone();
                let mut new_b = b.clone();
                while new_a.len() > player_a as usize {
                    new_a.pop_back();
                }
                while new_b.len() > player_b as usize {
                    new_b.pop_back();
                }
                let answer: bool = play(new_a, new_b, game_no + 1);
                println!("...anyway, back to game {}.", game_no);
                if answer {
                    a.push_back(player_a);
                    a.push_back(player_b);
                    println!("Player 1 wins round {} of game {}!", round - 1, game_no);
                } else {
                    b.push_back(player_b);
                    b.push_back(player_a);
                    println!("Player 2 wins round {} of game {}!", round - 1, game_no);
                }
            } else {
                if player_a > player_b {
                    println!("Player 1 wins round {} of game {}!", round - 1, game_no);
                    a.push_back(player_a);
                    a.push_back(player_b);
                } else if player_a < player_b {
                    println!("Player 2 wins round {} of game {}!", round - 1, game_no);
                    b.push_back(player_b);
                    b.push_back(player_a);
                } else {
                    panic!("ai de plm!");
                }
            }
        }
        seen.insert((player_a, player_b));
        println!("");
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
