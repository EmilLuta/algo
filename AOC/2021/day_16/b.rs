use std::collections::HashMap;
use std::env;
use std::fs;

struct Packet {
    bits: Vec<u8>,
    version: i64,
    type_id: i64,
}

fn hex_to_bin(data: String, hex_map: &HashMap<char, Vec<u8>>) -> Vec<u8> {
    let mut bin: Vec<u8> = vec![];
    for c in data.chars() {
        bin.append(&mut (*hex_map.get(&c).unwrap()).clone());
    }
    bin
}

fn bin_to_i64(bin: Vec<u8>) -> i64 {
    let mut answer = 0;
    for v in bin {
        answer = answer * 2 + v as i64;
    }
    answer
}

fn slice_to_i64(slice: &[u8]) -> i64 {
    let mut answer = 0;
    for v in slice {
        answer = answer * 2 + *v as i64;
    }
    answer
}

impl Packet {
    fn new(bits: Vec<u8>) -> Packet {
        let version = slice_to_i64(&bits[..3]);
        let type_id = slice_to_i64(&bits[3..6]);
        Packet {
            bits,
            version,
            type_id,
        }
    }

    fn parse(&self) -> (i64, usize) {
        let mut value = 0;
        let mut index = 6;
        if self.type_id != 4 {
            let mut values: Vec<i64> = vec![];
            let length_type = self.bits[index];
            index += 1;
            if length_type == 0 {
                let len = slice_to_i64(&self.bits[index..index + 15]) as usize;
                index += 15;
                let mut start = 0;
                while start < len {
                    let new_data = self.bits[index..].to_vec();
                    let packet = Packet::new(new_data);
                    let (new_val, ended) = packet.parse();
                    values.push(new_val);
                    index += ended;
                    start += ended;
                }
            } else {
                let count = slice_to_i64(&self.bits[index..index + 11]);
                index += 11;
                for _ in 0..count {
                    let new_data = self.bits[index..].to_vec();
                    let packet = Packet::new(new_data);
                    let (new_val, ended) = packet.parse();
                    values.push(new_val);
                    index += ended;
                }
            }
            value = match self.type_id {
                0 => values.iter().sum(),
                1 => values.iter().product(),
                2 => *values.iter().min().unwrap(),
                3 => *values.iter().max().unwrap(),
                5 => {
                    if values[0] > values[1] {
                        1
                    } else {
                        0
                    }
                }
                6 => {
                    if values[0] < values[1] {
                        1
                    } else {
                        0
                    }
                }
                7 => {
                    if values[0] == values[1] {
                        1
                    } else {
                        0
                    }
                }
                _ => panic!("Wrong type_id"),
            };
        } else {
            let mut keep_going = true;
            let mut val: Vec<u8> = vec![];
            while keep_going {
                if self.bits[index] == 0 {
                    keep_going = false;
                }
                for i in index + 1..index + 5 {
                    val.push(self.bits[i]);
                }
                index += 5;
            }
            value = bin_to_i64(val);
        }
        (value, index)
    }
}

fn main() {
    let hex_map: HashMap<char, Vec<u8>> = HashMap::from([
        ('0', vec![0, 0, 0, 0]),
        ('1', vec![0, 0, 0, 1]),
        ('2', vec![0, 0, 1, 0]),
        ('3', vec![0, 0, 1, 1]),
        ('4', vec![0, 1, 0, 0]),
        ('5', vec![0, 1, 0, 1]),
        ('6', vec![0, 1, 1, 0]),
        ('7', vec![0, 1, 1, 1]),
        ('8', vec![1, 0, 0, 0]),
        ('9', vec![1, 0, 0, 1]),
        ('A', vec![1, 0, 1, 0]),
        ('B', vec![1, 0, 1, 1]),
        ('C', vec![1, 1, 0, 0]),
        ('D', vec![1, 1, 0, 1]),
        ('E', vec![1, 1, 1, 0]),
        ('F', vec![1, 1, 1, 1]),
    ]);

    let args: Vec<String> = env::args().collect();
    let packets: Vec<Packet> = fs::read_to_string(&args[1])
        .unwrap()
        .lines()
        .map(|l| Packet::new(hex_to_bin(l.to_string(), &hex_map)))
        .collect();
    let mut answer = 0;
    for packet in packets {
        let (value, _) = packet.parse();
        println!("value = {}", value);
        answer += value;
    }
    println!("answer = {}", answer);
}
