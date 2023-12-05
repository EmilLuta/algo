use std::cmp::{PartialEq, PartialOrd};
use std::env;
use std::fs;

#[derive(Ord, Eq, PartialOrd, PartialEq, Debug)]
struct Mapping {
    src: u64,
    dst: u64,
    range: u64,
}

#[derive(Debug)]
struct Manual {
    seeds: Vec<u64>,
    mappings: Vec<Vec<Mapping>>,
}

impl Manual {
    fn search(val: u64, mapping: &Vec<Mapping>) -> u64 {
        let mut left = 0;
        let mut right = mapping.len() as i32 - 1;
        while left <= right {
            let mid = (left + (right - left) / 2) as usize;
            let map = &mapping[mid];
            if map.src <= val && val < map.src + map.range {
                return map.dst + val - map.src;
            }
            if val < map.src {
                right = mid as i32 - 1;
            } else {
                left = mid as i32 + 1;
            }
        }
        val
    }

    fn mapping_for(&self, seed: u64) -> u64 {
        let mut val = seed;

        for mapping in &self.mappings {
            val = Self::search(val, mapping);
        }
        val
    }

    fn new(lines: Vec<String>) -> Self {
        let seeds: Vec<u64> = lines[0]
            .split("seeds: ")
            .nth(1)
            .unwrap()
            .split(' ')
            .map(|seed| seed.parse::<u64>().unwrap())
            .collect();
        let mut index = 2;
        let headers = [
            "seed-to-soil",
            "soil-to-fertilizer",
            "fertilizer-to-water",
            "water-to-light",
            "light-to-temperature",
            "temperature-to-humidity",
            "humidity-to-location",
        ];
        let mut h_i = 0;
        let mut mappings: Vec<Vec<Mapping>> = vec![];
        while index < lines.len() {
            assert!(lines[index].starts_with(headers[h_i]));
            index += 1;
            h_i += 1;
            let mut mapping_for_header = vec![];
            while index < lines.len() && !lines[index].is_empty() {
                let mut raw_mapping = lines[index].split(' ');
                let dst = raw_mapping.next().unwrap().parse::<u64>().unwrap();
                let src = raw_mapping.next().unwrap().parse::<u64>().unwrap();
                let range = raw_mapping.next().unwrap().parse::<u64>().unwrap();
                mapping_for_header.push(Mapping { dst, src, range });
                index += 1;
            }
            mapping_for_header.sort();
            mappings.push(mapping_for_header);
            index += 1;
        }
        Manual { seeds, mappings }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines: Vec<String> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|line| line.to_string())
        .collect();
    let manual = Manual::new(lines);
    let mut answer = u64::MAX;
    for seed_data in manual.seeds.chunks(2) {
        for seed in seed_data[0]..seed_data[0] + seed_data[1] {
            answer = std::cmp::min(answer, manual.mapping_for(seed));
        }
    }
    println!("answer = {:?}", answer);
}
