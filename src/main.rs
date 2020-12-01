fn main() -> Result<(), Box<dyn std::error::Error>> {
    // use puzzle part 2 instead of puzzle part 1
    let part = 2;

    // read the file
    let input = std::fs::read_to_string("src/input.txt")?;

    // split file input from string to list
    let list : Vec<&str> = input.split('\n').collect();
    // convert list of strings to integers
    let numbers : Vec<i32> = list.iter().map(|&n| n.parse::<i32>().unwrap()).collect();

    if part == 1 {
        for i in &numbers {
            for j in &numbers {
                if i + j == 2020 {
                    println!("answer:{}", i * j);
                    return Ok(());
                }
            }
        }
    }
    else if part == 2 {
        for i in &numbers {
            for j in &numbers {
                for k in &numbers {
                    if i + j + k == 2020 {
                        println!("answer:{}", i * j * k);
                        return Ok(());
                    }
                }
            }
        }
    }

    Ok(())
}
