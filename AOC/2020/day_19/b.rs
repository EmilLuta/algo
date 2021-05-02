use std::collections::{HashMap, HashSet};
use std::{env, fs};

fn dfs(graph: &HashMap<String, Vec<Vec<String>>>, node: String) -> HashSet<String> {
    let mut answer: HashSet<String> = HashSet::new();
    for rules in graph.get(&node) {
        for rule in rules {
            let mut currs: Vec<String> = vec![String::new()];
            for new_node in rule {
                let c: char = new_node.as_bytes()[0] as char;
                if 'a' <= c && c <= 'z' {
                    let mut new_container: Vec<String> = vec![];
                    for curr in &currs {
                        new_container.push(curr.to_string() + &c.to_string());
                    }
                    currs = new_container;
                    continue;
                }
                let mut new_container: Vec<String> = vec![];
                for opt in dfs(graph, new_node.to_string()) {
                    for curr in &currs {
                        new_container.push(curr.to_string() + &opt);
                    }
                }
                currs = new_container;
            }
            for curr in &currs {
                answer.insert(curr.to_string());
            }
        }
    }
    answer
}

fn get_graph(rules: Vec<String>) -> HashMap<String, Vec<Vec<String>>> {
    let mut graph_raw: HashMap<String, String> = HashMap::new();
    for rule in rules {
        let k_v: Vec<&str> = rule.split(": ").collect();
        graph_raw.insert(k_v[0].to_string(), k_v[1].to_string());
    }
    let mut graph: HashMap<String, Vec<Vec<String>>> = HashMap::new();
    for rule in graph_raw {
        let all_options: Vec<&str> = rule.1.split(" | ").collect();
        for opt in all_options {
            let val = opt
                .trim_end_matches("\"")
                .trim_start_matches("\"")
                .to_string();
            let vals: Vec<String> = val.split(" ").into_iter().map(|v| v.to_string()).collect();
            if graph.contains_key(&rule.0) {
                let mut values = graph.get(&rule.0).unwrap().to_vec();
                values.push(vals.to_vec());
                graph.insert(rule.0.clone(), values);
            } else {
                graph.insert(rule.0.clone(), vec![vals.to_vec()]);
            }
        }
    }
    graph
}

fn check_recursive_match(graph: &HashMap<String, Vec<Vec<String>>>, message: String) -> bool {
    let n = message.len();
    let mut combos: Vec<(usize, usize)> = vec![];
    let forty_two = dfs(&graph, "42".to_string());
    let thirty_one = dfs(&graph, "31".to_string());
    let mut first_len: usize = 0;
    let mut second_len: usize = 0;
    for x in &forty_two {
        first_len = x.len();
        break;
    }
    for x in &thirty_one {
        second_len = x.len();
        break;
    }
    for i in 1..n / first_len + 1 {
        for j in 1..n / (first_len + second_len) + 1 {
            if i * first_len + j * (first_len + second_len) == n {
                combos.push((i, j));
            }
        }
    }
    if combos.len() > 0 {
        for combo in combos {
            let mut i = 0;
            let mut ok = true;
            for _ in 0..combo.0 + combo.1 {
                let slice = &message[i..i + first_len].to_string();
                if !forty_two.contains(slice) {
                    ok = false;
                }
                i += first_len;
            }
            for _ in 0..combo.1 {
                let slice = &message[i..i + second_len].to_string();
                if !thirty_one.contains(slice) {
                    ok = false;
                }
                i += second_len;
            }
            if ok {
                return true;
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
        .map(|line| line.to_string())
        .collect();
    let mut rules: Vec<String> = vec![];
    let mut messages: Vec<String> = vec![];
    let mut add_rules: bool = true;
    for line in lines {
        if line.is_empty() {
            add_rules = false;
            continue;
        }
        if add_rules {
            rules.push(line.clone());
        } else {
            messages.push(line.clone());
        }
    }
    let graph = get_graph(rules);
    let possible_options: HashSet<String> = dfs(&graph, "0".to_string());
    let mut answer: i32 = 0;
    for message in &messages {
        if possible_options.contains(message) || check_recursive_match(&graph, message.to_string())
        {
            answer += 1;
        }
    }
    println!("{}", answer);
}
