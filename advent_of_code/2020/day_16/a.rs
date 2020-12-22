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
    let mut category_mapping: HashMap<String, ((i32, i32), (i32, i32))> = HashMap::new();
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
                let (key, value) = parse_category(lines[i].clone());
                category_mapping.insert(key, value);
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
    // println!("category_mapping {:#?}", category_mapping);
    println!("my ticket {:#?}", my_ticket);
    let mut answer: i32 = 0;
    for ticket in tickets {
        for ticket_val in ticket {
            let mut ok: bool = false;
            for ok_range in category_mapping.values() {
                if (ok_range.0 .0 <= ticket_val && ticket_val <= ok_range.0 .1)
                    || (ok_range.1 .0 <= ticket_val && ticket_val <= ok_range.1 .1)
                {
                    ok = true;
                }
            }
            if !ok {
                answer += ticket_val;
            }
        }
    }
    println!("answer = {}", answer);
}
