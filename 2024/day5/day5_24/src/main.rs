use regex::Regex;
use std::fs;

const PUZZLE_PATH: &str = "static/puzzle_input.txt";

fn main() {
    let input = fs::read_to_string(PUZZLE_PATH).unwrap();
    // println!("{input}");
    let order_regex = Regex::new(r"\|").unwrap();
    let page_regex = Regex::new(r"\,").unwrap();

    let mut order: Vec<String> = Vec::new();
    order.reserve(1008);

    let mut order_entries: Vec<usize> = Vec::new();
    let mut orders: Vec<Vec<usize>> = Vec::new();
    let mut page_entries: Vec<usize> = Vec::new();
    let mut pages: Vec<Vec<usize>> = Vec::new();

    for line in input.lines() {
        if order_regex.is_match(line) {
            let nums: Vec<usize> = line
                .split('|')
                .map(|s| s.trim().parse::<usize>().unwrap())
                .collect();
            orders.push(nums);
        } else if page_regex.is_match(line){
            let nums: Vec<usize> = line
                .split(',')
                .map(|s| s.trim().parse::<usize>().unwrap())
                .collect();
            pages.push(nums);
        }
    }

    let mut sum_1: usize = 0;
    for page_seq in &mut pages {
        let mut valid: bool = true;
        for order_rule in &orders {
            let a = order_rule[0];
            let b = order_rule[1];

            let pos_a = page_seq.iter().position(|&x| x == a);
            let pos_b = page_seq.iter().position(|&x| x == b);

            if let (Some(pa), Some(pb)) = (pos_a, pos_b) {
                if pa > pb {
                    valid = false;
                    break;
                }
            }
        }
        if valid {
            sum_1 += page_seq[page_seq.len() / 2];
        } else {
            // eprintln!("INVALID");
        }
    }

    println!("");
    println!("{}", sum_1);

    let mut sum_2: usize = 0;
    for page_seq in &mut pages {
        let mut swapped_once = false;

        loop {
            let mut swapped = false;

            for order_rule in &orders {
                let a = order_rule[0];
                let b = order_rule[1];
                
                let pos_a = page_seq.iter().position(|&x| x == a);
                let pos_b = page_seq.iter().position(|&x| x == b);

                if let (Some(pa), Some(pb)) = (pos_a, pos_b) {
                    if pa > pb {
                        page_seq.swap(pa, pb);
                        swapped = true;
                        swapped_once = true;
                    }
                }
            }
            // if this pass made no swaps, it's fully ordered now
            if !swapped {
                break;
            }
        }

        // only add if this sequence was originally invalid
        if swapped_once {
            sum_2 += page_seq[page_seq.len() / 2];
        }
    }

    println!("");
    println!("{}", sum_2);
}
