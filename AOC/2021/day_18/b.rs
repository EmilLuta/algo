use std::cmp::max;
use std::env;
use std::fs;

const RADIX: u32 = 10;

#[derive(Debug, Clone, Copy)]
struct Node {
    left: Option<usize>,
    right: Option<usize>,
    parent: Option<usize>,
    val: Option<i64>,
    index: usize,
}

impl Node {
    fn new(data: &str, tree_list: &mut Vec<Node>, parent: Option<usize>) -> usize {
        let mut all_digits: bool = true;
        let mut val = 0;
        for c in data.chars() {
            if '0' <= c && c <= '9' {
                let digit = c.to_digit(RADIX).expect("Character must be a digit") as i64;
                val = val * 10 + digit;
                continue;
            }
            all_digits = false;
            break;
        }
        if all_digits {
            let node = Node {
                left: None,
                right: None,
                val: Some(val),
                index: tree_list.len(),
                parent,
            };
            tree_list.push(node);
            return node.index;
        }
        let mut left_start: Option<usize> = None;
        let mut left_end: Option<usize> = None;
        let mut right_start: Option<usize> = None;
        let mut right_end: Option<usize> = None;
        let mut count = 0;
        for (i, c) in data.chars().enumerate() {
            if c == '[' && left_start == None {
                left_start = Some(i + 1);
                continue;
            }
            if c == ',' && count == 0 && left_end == None {
                left_end = Some(i);
                right_start = Some(i + 1);
                continue;
            }
            if c == ']' && count == 0 && right_end == None {
                right_end = Some(i);
            }
            if c == '[' {
                count += 1;
            }
            if c == ']' {
                count -= 1;
            }
        }
        let left_start = left_start.expect("left_start must be found");
        let left_end = left_end.expect("left_end must be found");
        let right_start = right_start.expect("right_start must be found");
        let right_end = right_end.expect("right_end must be found");
        let index = tree_list.len();
        let mut node = Node {
            left: None,
            right: None,
            val: None,
            index,
            parent,
        };
        tree_list.push(node);
        let left = Node::new(&data[left_start..left_end], tree_list, Some(index));
        let right = Node::new(&data[right_start..right_end], tree_list, Some(index));
        node.left = Some(left);
        node.right = Some(right);
        tree_list[index] = node;
        index
    }

    fn print(&self, tree_list: &Vec<Node>) {
        if self.val != None {
            print!("{}", self.val.expect("value must be some(_) on node"));
            return;
        }
        print!("[");
        assert!(tree_list[self.left.unwrap()].parent.unwrap() == self.index);
        tree_list[self.left.expect("left must be available")].print(&tree_list);
        print!(",");
        assert!(tree_list[self.right.unwrap()].parent.unwrap() == self.index);
        tree_list[self.right.expect("right must be available")].print(&tree_list);
        print!("]");
    }
}

#[derive(Debug, Clone)]
struct Number {
    tree_list: Vec<Node>,
    root: usize,
}

impl Number {
    fn new(data: &str) -> Number {
        let mut tree_list: Vec<Node> = vec![];
        let root = Node::new(&data, &mut tree_list, None);
        Number { tree_list, root }
    }

    fn fix_left(&mut self, mut left_id: usize, mut parent_opt: Option<usize>, to_add: i64) {
        while parent_opt != None {
            let parent_id = parent_opt.unwrap();
            if self.tree_list[parent_id].left.unwrap() != left_id {
                let mut right_id = self.tree_list[parent_id].left.unwrap();
                while self.tree_list[right_id].val == None {
                    right_id = self.tree_list[right_id].right.unwrap();
                }
                let mut node = self.tree_list[right_id];
                node.val = Some(node.val.unwrap() + to_add);
                self.tree_list[right_id] = node;
                return;
            }
            left_id = parent_id;
            parent_opt = self.tree_list[parent_id].parent;
        }
    }

    fn fix_right(&mut self, mut right_id: usize, mut parent_opt: Option<usize>, to_add: i64) {
        while parent_opt != None {
            let parent_id = parent_opt.unwrap();
            if self.tree_list[parent_id].right.unwrap() != right_id {
                let mut left_id = self.tree_list[parent_id].right.unwrap();
                while self.tree_list[left_id].val == None {
                    left_id = self.tree_list[left_id].left.unwrap();
                }
                let mut node = self.tree_list[left_id];
                node.val = Some(node.val.unwrap() + to_add);
                self.tree_list[left_id] = node;
                return;
            }
            right_id = parent_id;
            parent_opt = self.tree_list[parent_id].parent;
        }
    }

    fn explode(&mut self, node_id: usize, level: usize) -> bool {
        let node = self.tree_list[node_id];
        if node.val != None {
            assert!(level <= 5);
            return false;
        }
        assert!(level <= 5);
        if level == 5 {
            assert!(self.tree_list[node.left.unwrap()].val != None);
            assert!(self.tree_list[node.right.unwrap()].val != None);
            self.fix_left(
                node.left.unwrap(),
                Some(node_id),
                self.tree_list[node.left.unwrap()].val.unwrap(),
            );
            self.fix_right(
                node.right.unwrap(),
                Some(node_id),
                self.tree_list[node.right.unwrap()].val.unwrap(),
            );
            let mut node = node;
            node.left = None;
            node.right = None;
            node.val = Some(0);
            self.tree_list[node.index] = node;
            return true;
        }
        self.explode(node.left.unwrap(), level + 1) || self.explode(node.right.unwrap(), level + 1)
    }

    fn split(&mut self, node_id: usize) -> bool {
        let mut node = self.tree_list[node_id];
        if node.val == None {
            return self.split(node.left.unwrap()) || self.split(node.right.unwrap());
        }
        let val = node.val.unwrap();
        if val > 9 {
            let left_index = self.tree_list.len();
            let left = Node {
                left: None,
                right: None,
                val: Some(val / 2),
                index: left_index,
                parent: Some(node.index),
            };
            self.tree_list.push(left);
            let right_index = self.tree_list.len();
            let mut right_val = val / 2;
            if val % 2 == 1 {
                right_val += 1;
            }
            let right = Node {
                left: None,
                right: None,
                val: Some(right_val),
                index: right_index,
                parent: Some(node.index),
            };
            self.tree_list.push(right);
            node.val = None;
            node.right = Some(right_index);
            node.left = Some(left_index);
            self.tree_list[node_id] = node;
            return true;
        }
        false
    }

    fn add(&mut self, other: &mut Number) {
        let start_index = self.tree_list.len();
        for node in &other.tree_list {
            let left = match node.left {
                Some(v) => Some(v + start_index),
                None => None,
            };
            let right = match node.right {
                Some(v) => Some(v + start_index),
                None => None,
            };
            let parent = match node.parent {
                Some(v) => Some(v + start_index),
                None => None,
            };
            self.tree_list.push(Node {
                left,
                right,
                val: node.val,
                index: node.index + start_index,
                parent,
            });
        }
        let left_index = self.root;
        let right_index = other.root + start_index;
        let root = Node {
            left: Some(left_index),
            right: Some(right_index),
            val: None,
            index: self.tree_list.len(),
            parent: None,
        };
        self.tree_list.push(root);
        self.root = root.index;
        self.tree_list[left_index].parent = Some(self.root);
        self.tree_list[right_index].parent = Some(self.root);
        let mut changes = true;
        while changes {
            changes = self.explode(self.root, 1);
            if !changes {
                changes = self.split(self.root);
            }
        }
    }

    fn magnitude(&self, node_id: usize) -> i64 {
        let node = self.tree_list[node_id];
        if node.val != None {
            return node.val.unwrap();
        }
        3 * self.magnitude(node.left.unwrap()) + 2 * self.magnitude(node.right.unwrap())
    }

    fn print(&self) {
        self.tree_list[self.root].print(&self.tree_list);
        print!("\n");
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .expect("File exists")
        .lines()
        .map(|l| l.to_string())
        .collect();
    let mut numbers = vec![];
    for i in 0..lines.len() {
        numbers.push(Number::new(&lines[i]));
    }
    let n = numbers.len();
    let mut answer = 0;
    for i in 0..n {
        for j in 0..n {
            if i == j {
                continue;
            }
            let mut first = numbers[i].clone();
            let mut second = numbers[j].clone();
            first.add(&mut second);
            answer = max(answer, first.magnitude(first.root));
        }
    }
    println!("answer = {}", answer);
}
