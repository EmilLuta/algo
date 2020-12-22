use std::collections::BTreeSet;
use std::env;
use std::fs;

fn get_result(buffer: String) -> (String, bool) {
    let (key, value) = parse_buffer(buffer);
    let ok: bool = match &key[..] {
        "byr" => {
            let year = value.parse::<i32>().unwrap();
            1920 <= year && year <= 2002
        },
        "iyr" => {
            let year = value.parse::<i32>().unwrap();
            2010 <= year && year <= 2020
        },
        "eyr" => {
            let year = value.parse::<i32>().unwrap();
            2020 <= year && year <= 2030
        },
        "hgt" => {
            let bytes = value.as_bytes();
            let n = bytes.len();
            if n <= 2 {
                false
            } else {
                let height = std::str::from_utf8(&bytes[0..n - 2]).unwrap().parse::<i32>().unwrap();
                let mut good = false;
                if bytes[n - 2] == 'c' as u8 && bytes[n - 1] == 'm' as u8 {
                    good = good || (150 <= height && height <= 193);
                }
                if bytes[n - 2] == 'i' as u8 && bytes[n - 1] == 'n' as u8 {
                    good = good || (59 <= height && height <= 76);
                }
                good
            }
        },
        "hcl" => {
            let mut good = true;
            let bytes = value.as_bytes();
            let n = bytes.len();
            if n != 7 {
                good = false;
            }
            if bytes[0] as char != '#' {
                good = false;
            }
            for i in 1..n {
                let c = bytes[i] as char;
                if !(('0' <= c && c <= '9') || ('a' <= c && c <= 'f')) {
                    good = false;
                }
            }
            good
        },
        "ecl" => {
            let mut good = false;
            let eye_colours = vec!{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
            for color in eye_colours {
                good = good || value == color.to_string();
            }
            good
        },
        "pid" => {
            let n = value.as_bytes().len();
            if n != 9 {
                false
            } else {
                let mut good = true;
                for b in value.as_bytes() {
                    if '0' > *b as char || *b as char > '9' {
                        good = false;
                    }
                }
                good
            }
        },
        _ => false,
    };
    (key, ok)
}

fn parse_buffer(buffer: String) -> (String, String) {
    if buffer.len() == 0 {
        return (String::new(), String::new());
    }

    let mut key: String = String::new();
    let mut value: String = String::new();
    let mut found = false;
    for extra in buffer.as_bytes() {
        let our_char = *extra as char;
        if our_char == ':' {
            found = true;
        } else {
            if found {
                value.push(our_char);
            } else {
                key.push(our_char);
            }
        }
    }
    return (key, value);
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .split("\n\n")
        .filter(|line| !line.is_empty())
        .map(|line| line.to_string())
        .collect();
    let mut answer = 0;
    for entry in lines {
        let mut buffer: String = String::new();
        let fields: Vec<&str> = vec!{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
        let mut expected: BTreeSet<String> = fields.iter().map(|field| field.to_string()).collect();
        for b in entry.as_bytes() {
            let c: char = *b as char;
            if c == ' ' || c == '\n' {
                let (key, ok): (String, bool) = get_result(buffer);
                if ok {
                    expected.remove(&key);
                }
                buffer = String::new();
            } else {
                buffer.push(c);
            }
        }
        let (key, ok): (String, bool) = get_result(buffer);
        if ok {
            expected.remove(&key);
        }
        if expected.len() == 0 {
            answer += 1;
        }
    }
    println!("{}", answer);
}
