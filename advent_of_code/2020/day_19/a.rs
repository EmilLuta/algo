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

fn get_options(rules: Vec<String>) -> HashSet<String> {
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
    let node: String = "0".to_string();
    dfs(&graph, node)
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
    let possible_options: HashSet<String> = get_options(rules);
    let mut answer: i32 = 0;
    for message in &messages {
        if possible_options.contains(message) {
            answer += 1;
        }
    }
    println!("{}", answer);
}
