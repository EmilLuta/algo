use std::collections::{HashMap, HashSet};
use std::env;
use std::fs;

fn dfs(
    graph: &HashMap<String, Vec<String>>,
    seen: &mut HashSet<String>,
    node: String,
    state: String,
) -> i32 {
    if node == "end" {
        if state.len() == 0 {
            return 1;
        }
        let mut lower = false;
        for c in state.chars() {
            if c.is_lowercase() {
                lower = true;
            }
            break;
        }
        if lower {
            return 0;
        } else {
            return 1;
        }
    }
    let mut lower: bool = false;
    for c in node.chars() {
        lower = c.is_lowercase();
        break;
    }
    let mut answer = 0;
    if lower {
        for child in graph.get(&node).unwrap() {
            if !seen.contains(child) {
                if state.len() == 0 && &node != "start" && &node != "end" {
                    answer += dfs(graph, seen, child.to_string(), node.clone());
                }
                seen.insert(node.clone());
                if &state == &node {
                    answer += dfs(graph, seen, child.to_string(), String::from("EMIL"));
                } else {
                    answer += dfs(graph, seen, child.to_string(), state.clone());
                }
                seen.remove(&node);
            }
        }
    } else {
        for child in graph.get(&node).unwrap() {
            if !seen.contains(child) {
                answer += dfs(graph, seen, child.to_string(), state.clone());
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
        .map(|line| line.to_string())
        .collect();
    let mut graph: HashMap<String, Vec<String>> = HashMap::new();
    for line in &lines {
        let mut iter = line.split("-");
        let node_1 = iter.next().unwrap();
        let node_2 = iter.next().unwrap();
        let entry_1 = graph.entry(node_1.to_string()).or_insert(vec![]);
        entry_1.push(node_2.to_string());
        let entry_2 = graph.entry(node_2.to_string()).or_insert(vec![]);
        entry_2.push(node_1.to_string());
    }
    let mut seen: HashSet<String> = HashSet::new();
    let answer = dfs(&graph, &mut seen, "start".to_string(), "".to_string());
    println!("answer = {}", answer);
}
