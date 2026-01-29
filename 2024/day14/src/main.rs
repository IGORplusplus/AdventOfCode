use std::io::{BufReader, BufRead};
use std::fs::File;
use std::env::args;

#[derive(Debug, PartialEq, Clone, Copy)]
struct Robot {
    pos: (i32, i32),
    vel: (i32, i32),
}

static WIDTH: i32 = 101;
static HEIGHT: i32 = 103;

// static WIDTH: i32 = 11;
// static HEIGHT: i32 = 7;


// Reads and parses file input
fn read_path_to_string(file_path: &str) -> Vec<Robot> {

    let file_path = format!("static/{file_path}.txt");
    let file = File::open(file_path.to_owned()).expect("failed to open file");
    let bufread = BufReader::new(file);
    let mut robots: Vec<Robot> = Vec::new();

    // Parses each line
    for line_result in bufread.lines() {
        let line = line_result.unwrap();
        let values: Vec<&str> = line.split_whitespace().collect();

        let mut pos: (i32, i32) = (-1, -1);
        let mut vel: (i32, i32) = (-1, -1);
        for (i, value) in values.into_iter().enumerate() {
            let comma_index = value.find(|c: char| c == ',').unwrap();

            let first_value: i32 = value[2..comma_index]
                .to_owned()
                .parse::<i32>()
                .expect("Parse Error");
            let second_value: i32 = value[(comma_index+1)..=(value.len()-1)]
                .to_owned()
                .parse::<i32>()
                .expect("Parse Error");

            if i == 0 { // Pos
                pos = (first_value, second_value);
            } else {    // Vel
                vel = (first_value, second_value);
            }
        }

        let robot = Robot {
            pos,
            vel,
        };
        // println!("{}", line);
        // println!("{:?}", robot);
        robots.push(robot);
    }

    return robots;
}

// Makes the robots walk and returns their new positions
fn robots_walk(robots: &mut Vec<Robot>, ticks: i32) {
    for robot in robots {
        // println!("\nROBOT WALKING: {:?}", robot);

        //could be negative, could be positive
        let distance: (i32, i32) = ((robot.vel.0 * ticks) % WIDTH, (robot.vel.1 * ticks) % HEIGHT);

        let mut x_pos = (robot.pos.0 + distance.0) % WIDTH;
        let mut y_pos = (robot.pos.1 + distance.1) % HEIGHT;

        if x_pos < 0 {
            x_pos = WIDTH + x_pos;
        }
        if y_pos < 0 {
            y_pos = HEIGHT + y_pos;
        }

        let new_pos: (i32, i32) = (x_pos, y_pos);
        // let absolute_new_pos: (i32, i32) = (robot.pos.0 + distance.0, robot.pos.1 + distance.1);
        // let grid_x = absolute_new_pos.0 / WIDTH;
        // let grid_y = absolute_new_pos.1 / HEIGHT;
        // let relative_new_pos = (absolute_new_pos.0 - WIDTH * grid_x, absolute_new_pos.1 - HEIGHT * grid_y);
        // println!("\tNew pos: {:?}", new_pos);
        robot.pos = new_pos;
    }
}

fn calculate_safety(robots: Vec<Robot>) -> u32 {
    let mut top_left = 0;
    let mut top_right = 0;
    let mut bottom_left = 0;
    let mut bottom_right = 0;

    let mut height_ban: Vec<u32> = Vec::new();
    let mut width_ban: Vec<u32> = Vec::new();

    for robot in robots {
        let pos = robot.pos;

        // Top left
        if pos.0 < WIDTH / 2 && pos.1 < HEIGHT / 2 {
            top_left += 1;
        }


        // Top right
        if pos.0 > WIDTH / 2 && pos. 1 < HEIGHT / 2 {
            top_right += 1;
        }

        // Bottom left
        if pos.0 < WIDTH / 2 && pos.1 > HEIGHT / 2 {
            bottom_left += 1;
        }

        // Bottom right
        if pos.0 > WIDTH / 2 && pos.1 > HEIGHT / 2 {
            bottom_right += 1;
        }
    }
    println!("tl: {top_left}, tr: {top_right}, bl: {bottom_left}, br: {bottom_right}");

    return top_left * top_right * bottom_left * bottom_right;
}

//Prints grid
fn print_robots(robots: &Vec<Robot>) {
    let mut grid: Vec<Vec<char>> = Vec::new();
    for i in 0..HEIGHT {
        let fill_vector: Vec<char> = vec!['.'; (WIDTH) as usize];
        grid.push(fill_vector);
    }

    for robot in robots {
        let pos = robot.pos;
        grid[pos.1 as usize][pos.0 as usize] = 'X';
    }

    for row in grid {
        for col in row {
            print!("{col}");
        }
        print!("\n");
    }
}


fn main() {
    let arguments: Vec<String> = args().collect();
    let file_path = arguments[1].clone();

    let mut robots: Vec<Robot> = read_path_to_string(&file_path);
    // robots_walk(&mut robots, 100);
    // let safety = calculate_safety(robots);
    // println!("Safety: {}", safety);
    for i in 0..8900 {
        println!("{}", i+1);
        robots_walk(&mut robots, 1);
        print_robots(&robots);
        for _ in 0..3 {
            println!()
        }
    }
}
