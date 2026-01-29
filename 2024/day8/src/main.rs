use std::fs;

const PUZZLE_PATH: &str = "static/puzzle_input.txt";

fn main() {
    let input = fs::read_to_string(PUZZLE_PATH).unwrap();

    println!("{}", input);
}
