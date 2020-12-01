fn main() -> Result<(), Box<dyn std::error::Error>> {
    let input = std::fs::read_to_string("src/input.txt")?;
    let part = 2;

    let list : Vec<&str> = input.split('\n').collect();
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
