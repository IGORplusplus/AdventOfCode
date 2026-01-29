use std::{fs, io};

fn read_lines(path: &str) -> std::io::Result<Vec<String>>{
    let contents = fs::read_to_string(path)?;
    Ok(contents.lines().map(String::from).collect())
}

fn _change_char_at_index(s: String, index: usize, new_char: char) -> String {
    let mut chars: Vec<_> = s.chars().collect();

    if index > chars.len() {
        eprintln!("Error: index out of bounds;");
    } else {
        chars[index] = new_char;
    }

    chars.into_iter().collect()
}

fn main() -> io::Result<()> {
    let path = "puzzle_input.txt";
    // let path = "puzzle_test.txt";
    let lines_vec = read_lines(path)?;

    println!("{:#?}", lines_vec);

    let mut active: Vec<usize> = Vec::new();
    let mut result: Vec<String> = Vec::new();
    let mut answer: usize = 0;

    for (row_idx, line) in lines_vec.iter().enumerate() {
        let mut new_line: Vec<char> = line.chars().collect();

        // first row: find S
        if row_idx == 0 {
            if let Some(i) = new_line.iter().position(|&c| c == 'S') {
                active.push(i);
            }
            println!("{}", new_line.iter().collect::<String>());
            continue;
        }

        let mut next_active = Vec::new();

        for &i in &active {
            match new_line.get(i) {
                Some('^') => {
                    if i > 0 {
                        new_line[i - 1] = '|';
                        next_active.push(i - 1);
                    }
                    if i + 1 < new_line.len() {
                        new_line[i + 1] = '|';
                        next_active.push(i + 1);
                    }
                    answer += 1;
                }
                Some('.') => {
                    new_line[i] = '|';
                    next_active.push(i);
                }
                _ => {}
            }
        }

        active = next_active;
        println!("{}", new_line.iter().collect::<String>());
        result.push(new_line.iter().collect::<String>());
    }

    println!("{:#?}\n{}", result, answer);
    Ok(())
}
