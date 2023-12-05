use std::collections::HashMap;
use std::env;
use std::fs;

struct Game {
    cubes: HashMap<String, i32>,
}

impl Game {
    fn new(line: &str) -> Result<Self, String> {
        let mut id_split = line.split(": ");
        id_split.next();
        let mut max_per_color: HashMap<String, i32> = HashMap::new();
        for pulls in id_split.next().unwrap().split("; ") {
            for pull in pulls.split(", ") {
                let color_value_raw: Vec<&str> = pull.split(' ').collect();
                let color = color_value_raw[1];
                let value = color_value_raw[0].parse::<i32>().unwrap();
                let curr_val = max_per_color
                    .entry(color.to_string())
                    .or_insert(0);
                *curr_val = std::cmp::max(*curr_val, value);
            }
        }
        Ok(Game {
            cubes: max_per_color,
        })
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let games: Vec<Game> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Game::new(line).unwrap())
        .collect();
    let answer: i32 = games
        .iter()
        .map(|game| game.cubes.get("green").unwrap() * game.cubes.get("red").unwrap() * game.cubes.get("blue").unwrap())
        .sum();
    println!("answer = {answer:?}");
    // for round in rounds {
    //     if s
    // }
}
