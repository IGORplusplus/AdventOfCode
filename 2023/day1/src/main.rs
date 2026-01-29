use std::env::args;
// use std::fmt::format;
use std::io::{BufReader, BufRead};

use std::fs::File;

pub fn convert_string_to_digit(number_string: &str) -> i8 {
    match number_string{
        "one" => 1,     
        "two" => 2,          
        "three" => 3,        
        "four" => 4,         
        "five" => 5,         
        "six" => 6,          
        "seven" => 7,        
        "eight" => 8,
        "nine" => 9,
        "1" => 1,
        "2" => 2,
        "3" => 3,
        "4" => 4,
        "5" => 5,
        "6" => 6,
        "7" => 7,
        "8" => 8,
        "9" => 9,
        _ => -1,
    }
}

fn main() {
    let args: Vec<String> = args().collect();

    let file_name: String = args[1].to_owned();
    // println!("{:?}", args);
    println!("{}", file_name);

    let file = File::open(format!("static/{}.txt",file_name)).expect("ermmm incorrect");
    let reader = BufReader::new(file);
    let mut lines: Vec<String> = Vec::new();

    for line in reader.lines() {
        lines.push(line.expect("failed to push string"));
    }

    /* println!("{:?}", lines);

    for _ in 0..10 {
        println!()
    } */

    let mut sum: u32 = 0;

    let string_digits: Vec<&str> = vec![
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    ];

    for line in &lines {

        // println!("{line}");

        let mut results: Vec<i8> = Vec::new();
        let mut indexes: Vec<i8> = Vec::new();

        for digit in &string_digits {
            for (i, _) in line.match_indices(digit) {
                let number = convert_string_to_digit(digit);
                results.push(number);
                indexes.push(i as i8);
            }
        }


        let max: usize = indexes.iter().enumerate().max_by_key(|&(_index, value)| value).unwrap().to_owned().0;
        let min: usize = indexes.iter().enumerate().min_by_key(|&(_index, value)| value).unwrap().to_owned().0;

        /* println!("{:?}", results);
        println!("{:?}", indexes);
        println!("min {}, max {}", min, max); */

        let tens: u32 = ( results[min] * 10 ) as u32;
        let ones: u32 = results[max] as u32;
        sum += tens + ones;
        /* println!("{line}");
        println!("{}, {ones}", tens / 10 ); */
    }
    println!("{}", sum)
}


        //first solution
        /* let first: u32 = line.find(|x| x.is_ascii_digit()).unwrap();
        let last: u32 = line.chars().rev().find(|x| x.is_ascii_digit()).unwrap().to_digit(10).unwrap();
        println!("{} -> {}, {}", line, first, last);
        let line_sum: u32 = (first * 10) + last;
        sum += line_sum;
        */

