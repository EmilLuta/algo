use std::env;

struct Point {
    x: i64,
    y: i64,
    z: i64,
}

struct Scanner {
    beacons: Vec<Point>,
    id: usize,
}

impl Scanner {
    fn all_from(Vec<String>) {

    }
}

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let scanners: Vec<Scanner> = Scanner::all_from(args);
}
