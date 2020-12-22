use std::{env, fs};

#[derive(Debug)]
struct Category {
    name: String,
    a_start: i32,
    a_end: i32,
    b_start: i32,
    b_end: i32,
    taken: bool,
}

impl Category {
    fn new(category: String) -> Category {
        let category_split: Vec<String> = category.split(": ").map(|x| x.to_string()).collect();
        let name: String = category_split[0].clone();
        let data: Vec<String> = category_split[1]
            .clone()
            .split(" or ")
            .map(|x| x.to_string())
            .collect();
        let a: Vec<i32> = data[0]
            .clone()
            .split("-")
            .map(|x| x.to_string().parse::<i32>().unwrap())
            .collect();
        let b: Vec<i32> = data[1]
            .clone()
            .split("-")
            .map(|x| x.to_string().parse::<i32>().unwrap())
            .collect();
        Category {
            name,
            a_start: a[0],
            a_end: a[1],
            b_start: b[0],
            b_end: b[1],
            taken: false,
        }
    }
}

#[derive(Debug)]
struct Ticket {
    vals: Vec<i32>,
}

impl Ticket {
    fn new(ticket: String) -> Ticket {
        Ticket {
            vals: ticket
                .clone()
                .split(",")
                .map(|x| x.to_string().parse::<i32>().unwrap())
                .collect(),
        }
    }

    fn get(&self, i: usize) -> i32 {
        self.vals[i]
    }
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
    let mut categories: Vec<Category> = vec![];
    let mut my_ticket: Ticket = Ticket { vals: vec![] };
    let mut all_tickets: Vec<Ticket> = vec![];
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
                categories.push(Category::new(lines[i].clone()));
            }
            "your_ticket" => {
                my_ticket = Ticket::new(lines[i].clone());
            }
            "tickets" => {
                all_tickets.push(Ticket::new(lines[i].clone()));
            }
            _ => {
                assert!(false);
            }
        }
        i += 1;
    }
    // println!("category_mapping {:#?}", category_mapping);
    let mut tickets: Vec<&Ticket> = vec![];
    for ticket in &all_tickets {
        let mut ticket_ok: bool = true;
        for val in &ticket.vals {
            let mut vals_ok: bool = false;
            for category in &categories {
                if (&category.a_start <= val && val <= &category.a_end)
                    || (&category.b_start <= val && val <= &category.b_end)
                {
                    vals_ok = true;
                }
            }
            ticket_ok = ticket_ok & vals_ok;
        }
        if ticket_ok {
            tickets.push(ticket);
        }
    }
    let mut index_to_categories: Vec<(String, usize)> = vec![(String::new(), 0); categories.len()];
    let mut left_to_occupy = categories.len();
    while left_to_occupy > 0 {
        for v_i in 0..my_ticket.vals.len() {
            let mut ok_categories_indices: Vec<usize> = vec![];
            for c_i in 0..categories.len() {
                let mut ok: bool = true;
                for t_i in 0..tickets.len() {
                    let val = tickets[t_i].get(v_i);
                    if !((categories[c_i].a_start <= val && val <= categories[c_i].a_end)
                        || (categories[c_i].b_start <= val && val <= categories[c_i].b_end))
                    {
                        // if t_i == 19 && &categories[c_i].name[..] == "departure location" {
                        //     println!("ce plm?\n");
                        // }
                        ok = false;
                    }
                }
                if ok {
                    ok_categories_indices.push(c_i);
                }
            }
            let mut free: i32 = 0;
            let mut option: usize = 0;
            for ok_index in ok_categories_indices {
                if !categories[ok_index].taken {
                    free += 1;
                    option = ok_index;
                }
            }
            if free == 1 {
                categories[option].taken = true;
                index_to_categories[v_i] = (categories[option].name.clone(), option);
                left_to_occupy -= 1;
            }
        }
    }
    let mut answer: i64 = 1;
    for i in 0..index_to_categories.len() {
        if index_to_categories[i].0.len() > 9 && &index_to_categories[i].0[..9] == "departure" {
            answer *= my_ticket.get(i) as i64;
        }
    }
    for i in 0..index_to_categories.len() {
        for j in 0..tickets.len() {
            let val = tickets[j].get(i);
            let cat = &categories[index_to_categories[i].1];
            if !((cat.a_start <= val && val <= cat.a_end)
                || (cat.b_start <= val && val <= cat.b_end))
            {
                println!(
                    "category {:#?} goes to index {}, i = {}, ticket[i] = {:#?}",
                    cat.name,
                    i,
                    j,
                    tickets[j].get(i)
                );
            }
        }
    }
    println!("{}", answer);
}
