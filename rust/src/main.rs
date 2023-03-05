use std::io;

fn main() {
    println!("welcome to guessing game!");
    println!("Enter a number : ");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess).expect("cannot read the line");

    println!("Your guess {}", guess);
}
