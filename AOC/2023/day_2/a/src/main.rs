use std::collections::HashMap;
use std::env;
use std::fs;

struct Game {
    id: i32,
    cubes: HashMap<String, i32>,
}

impl Game {
    fn new(line: &str) -> Result<Self, String> {
        let mut id_split = line.split(": ");
        let id = id_split
            .next()
            .unwrap()
            .strip_prefix("Game ")
            .unwrap()
            .parse::<i32>()
            .unwrap();
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
            id,
            cubes: max_per_color,
        })
    }

    fn possible(&self, available: &HashMap<String, i32>) -> bool {
        for (color, count) in &self.cubes {
            if available.get(color).unwrap() < count {
                return false;
            }
        }
        true
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let games: Vec<Game> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| Game::new(line).unwrap())
        .collect();
    let available: HashMap<String, i32> = [
        (String::from("red"), 12),
        (String::from("green"), 13),
        (String::from("blue"), 14),
    ]
    .iter()
    .cloned()
    .collect();
    let answer: i32 = games
        .iter()
        .filter(|game| game.possible(&available))
        .map(|game| game.id)
        .sum();
    println!("answer = {answer:?}");
    // for round in rounds {
    //     if s
    // }
}
