use std::collections::HashMap;
use std::{env, fs};

fn parse_category(category: String) -> (String, ((i32, i32), (i32, i32))) {
    let category_split: Vec<String> = category.split(": ").map(|x| x.to_string()).collect();
    let key: String = category_split[0].clone();
    let data: Vec<String> = category_split[1]
        .clone()
        .split(" or ")
        .map(|x| x.to_string())
        .collect();
    let first: Vec<i32> = data[0]
        .clone()
        .split("-")
        .map(|x| x.to_string().parse::<i32>().unwrap())
        .collect();
    let second: Vec<i32> = data[1]
        .clone()
        .split("-")
        .map(|x| x.to_string().parse::<i32>().unwrap())
        .collect();
    (key, ((first[0], first[1]), (second[0], second[1])))
}

fn parse_ticket(ticket: String) -> Vec<i32> {
    ticket
        .clone()
        .split(",")
        .map(|x| x.to_string().parse::<i32>().unwrap())
        .collect()
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let n: usize = lines.len();
    let mut parsing_mode = "categories".to_string();
    let mut i: usize = 0;
    let mut categories: Vec<(String, ((i32, i32), (i32, i32)))> = vec![];
    let mut my_ticket: Vec<i32> = vec![];
    let mut tickets: Vec<Vec<i32>> = vec![];
    while i < n {
        if lines[i].len() == 0 {
            parsing_mode = match &parsing_mode[..] {
                "categories" => {
                    i += 2;
                    "your_ticket".to_string()
                }
                "your_ticket" => {
                    i += 2;
                    "tickets".to_string()
                }
                _ => {
                    assert!(false);
                    "invalid".to_string()
                }
            };
            continue;
        };
        match &parsing_mode[..] {
            "categories" => {
                let category = parse_category(lines[i].clone());
                categories.push(category);
            }
            "your_ticket" => {
                my_ticket = parse_ticket(lines[i].clone());
            }
            "tickets" => {
                tickets.push(parse_ticket(lines[i].clone()));
            }
            _ => {
                assert!(false);
            }
        }
        i += 1;
    }
    let mut can_use: Vec<bool> = vec![true; categories.len()];
    let mut answer: i32 = 0;
    let mut map: HashMap<String, usize> = HashMap::new();
    let mut x = can_use.len();
    while x > 0 {
        for cat_i in 0..categories.len() {
            if !can_use[cat_i] {
                continue;
            }
            let ok_range = categories[cat_i].1;
            let mut good_indices: Vec<usize> = vec![];
            println!("checking category {}", categories[cat_i].0);
            for i in 0..tickets[0].len() {
                println!("checking column {}", i);
                let mut ok = true;
                for ticket in &tickets {
                    let ticket_val = ticket[i];
                    ok = ok
                        && ((ok_range.0 .0 <= ticket_val && ticket_val <= ok_range.0 .1)
                            || (ok_range.1 .0 <= ticket_val && ticket_val <= ok_range.1 .1));
                    println!("for ticket = {}, value is {}", ticket_val, ok);
                }
                if ok {
                    good_indices.push(i);
                }
                println!("works? {}", good_indices.len() != 0;);
            }
            if good_indices.len() > 0 {
                for index in good_indices {
                    for value in map.values() {
                        if index == value {
                            break;
                        }
                    }
                }
                can_use[cat_i] = false;
                map.insert(categories[cat_i].0.clone(), good_index);
                x -= 1;
            } else {
            }
        }
    }
    let mut answer = 1;
    println!("{:#?}", map);
    for (key, value) in map.iter() {
        println!("key = {:#?}, value = {:#?}", key, value);
        if key[..].contains("departure") {
            println!("ce plm");
            answer *= my_ticket[*value];
        }
    }
    println!("answer = {}", answer);
}
