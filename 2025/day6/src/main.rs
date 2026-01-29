use std::{fs, io};

fn read_lines(path: &str) -> std::io::Result<Vec<String>>{
    let contents = fs::read_to_string(path)?;
    Ok(contents.lines().map(String::from).collect())
}

#[derive(Debug)]
enum Operation {
    Multiplication,
    Addition,
}

fn main() -> io::Result<()>{
    let path = "puzzle_input.txt";
    // let path = "puzzle_test.txt";
    let lines_vec = read_lines(path)?;

    let rows = lines_vec.len();
    let cols = lines_vec[0].len();

    //must transpose matrix
    let lines_chars: Vec<Vec<char>> = lines_vec.iter()
        .map(|line| line.chars().collect())
        .collect();

    let mut grid: Vec<Vec<char>> = vec![vec![' ';rows + 1]; cols + 1];

    for i in 0..rows {
        for j in 0..lines_chars[i].len() {
            grid[j][i] = lines_chars[i][j];
        }
    }

    let grid_strings: Vec<String> = grid.iter()
        .map(|row| row.iter().collect())
        .collect();

    //this is good here, but I need to separate out and get rid of operations
    println!("{:#?}", grid_strings);

    let mut operations: Vec<Operation> = Vec::new();
    let mut operands: Vec<Vec<u64>> = Vec::new();
    let mut inner_operands: Vec<u64> = Vec::new();

    for line in &grid_strings {
        line.chars().for_each(|c| {
            match c {
                '*' => operations.push(Operation::Multiplication),
                '+' => operations.push(Operation::Addition),
                _=> {},
            }
        });

        let line_copy = line.trim_matches(' ');
        if line_copy.is_empty() {
            operands.push(inner_operands.clone());
            inner_operands.clear();
            continue;
        }

        let line_copy = line_copy.trim_matches(|c| matches!(c, '*' | '+'));
        let line_copy = line_copy.trim_matches(' ');
        let operand = line_copy.parse::<u64>().unwrap_or_default();
        inner_operands.push(operand);
    }
    operands.push(inner_operands);

    println!("{:?}", operations);
    println!("{:#?}", operands);

    let mut total: u64 = 0;
    let mut result: u64;

    for (i, op) in operations.iter().enumerate() {
        match op {
            Operation::Multiplication => {
                result = 1;
                for operand in operands[i].clone() {
                    result *= operand;
                }
                total += result;
            },
            Operation::Addition => {
                result = 0;
                for operand in operands[i].clone() {
                    result += operand;
                }
                total += result;
            },
        }
    }
    
    println!("Total: {}", total);
    Ok(())
}
