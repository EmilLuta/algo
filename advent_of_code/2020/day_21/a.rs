use std::collections::{HashMap, HashSet};
use std::{env, fs};

#[derive(Debug)]
struct Food {
    ingredients: HashSet<String>,
    allergens: HashSet<String>,
}

fn parse_food(line: String) -> Food {
    let ingredients_and_allergens: Vec<String> =
        line.split(" (contains ").map(|x| x.to_string()).collect();
    let ingredients: HashSet<String> = ingredients_and_allergens[0]
        .split(' ')
        .map(|x| x.to_string())
        .collect();
    let allergens: HashSet<String> = ingredients_and_allergens[1]
        [..ingredients_and_allergens[1].len() - 1]
        .split(", ")
        .map(|x| x.to_string())
        .collect();
    Food {
        ingredients,
        allergens,
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut foods: Vec<Food> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| parse_food(l.to_string()))
        .collect();
    let n: usize = foods.len();
    let mut allergen_to_index: HashMap<String, Vec<usize>> = HashMap::new();
    for i in 0..n {
        for allergen in &foods[i].allergens {
            let counter = allergen_to_index
                .entry(allergen.to_string())
                .or_insert(vec![]);
            counter.push(i);
        }
    }
    let mut found = true;
    let mut dangerous_ingredients: Vec<(String, String)> = vec![];
    while found {
        found = false;
        for allergen in allergen_to_index.keys() {
            let indices = allergen_to_index.get(allergen).unwrap();
            let mut ingredients: HashSet<String> = foods[indices[0]]
                .ingredients
                .clone()
                .iter()
                .map(|x| x.to_string())
                .collect();
            for i in indices {
                ingredients = ingredients
                    .intersection(&foods[*i].ingredients)
                    .map(|x| x.to_string())
                    .collect();
            }
            if ingredients.len() == 1 {
                found = true;
                let ingredients: Vec<String> = ingredients.iter().map(|x| x.to_string()).collect();
                let my_ingredient = &ingredients[0];
                dangerous_ingredients.push((allergen.clone(), my_ingredient.clone()));
                for k in 0..n {
                    foods[k].ingredients.remove(my_ingredient);
                    foods[k].allergens.remove(allergen);
                }
            }
        }
    }
    // let mut go = true;
    // while go {
    //     go = false;
    //     let mut keep_going = true;
    //     for i in 0..n {
    //         if !keep_going {
    //             break;
    //         }
    //         for j in 0..n {
    //             let ingredients: Vec<String> = foods[i]
    //                 .ingredients
    //                 .intersection(&foods[j].ingredients)
    //                 .map(|x| x.to_string())
    //                 .collect();
    //             let allergens: Vec<String> = foods[i]
    //                 .allergens
    //                 .intersection(&foods[j].allergens)
    //                 .map(|x| x.to_string())
    //                 .collect();
    //             if ingredients.len() == 1 && allergens.len() == 1 {
    //                 keep_going = false;
    //                 go = true;
    //                 for k in 0..n {
    //                     foods[k].ingredients.remove(&ingredients[0]);
    //                     foods[k].allergens.remove(&allergens[0]);
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    // }

    let mut answer: i32 = 0;
    println!("{:#?}", foods);
    for food in &foods {
        for _ in &food.ingredients {
            answer += 1;
        }
    }
    println!("{:#?}", answer);
    // for food in &foods {
    //     if food.allergens.contains("sesame") {
    //         println!("{:#?}", food.ingredients);
    //         println!("{:#?}", food.allergens);
    //     }
    //     // for allergens in food.allergens {

    //     // }
    // }
    let mut first = true;
    dangerous_ingredients.sort();
    for item in dangerous_ingredients {
        if !first {
            print!(",");
        }
        print!("{}", item.1);
        first = false;
    }
    println!("");
}
