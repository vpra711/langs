use std::{io};
fn main() 
{
    //io_ops();
    //datatypes();
    //condition_ops();
    arrays_loops();
}

fn io_ops()
{
    let mut name: String = String::new();
    println!("Enter name");
    io::stdin().read_line(&mut name).expect("nothing enterted");
    println!("heelo {}", name);
}

fn datatypes()
{
    println!("Integers");
    println!("u8 \nmin: {} \nmax: {}", u8::MIN, u8::MAX);
    println!("u16 \nmin: {} \n max: {}", u16::MIN, u16::MAX);
    println!("u32 \nmin: {} \nmax: {}", u32::MIN, u32::MAX);
    println!("u63 \nmin: {} \nmax: {}", u64::MIN, u64::MAX);
    println!("u128 \nmin: {} \nmax: {}", u128::MIN, u128::MAX);
    println!("usize \nmin: {} \n max: {}", usize::MIN, usize::MAX);
    println!("for signed integers use i inplace of u");

    println!("floats");
    println!("f32 \nmin: {} \nmax: {}", f32::MIN, f32::MAX);
    println!("f64 \nmin: {} \nmax: {}", f64::MIN, f64::MAX);

    println!("chars, strings, booleans, arrays, tuple and etc");

}

fn condition_ops()
{
    let mobile: String = String::from("samsung");

    match mobile.len()
    {
        _45 => println!("between 1 and 12"),
        _8 => println!("samsung"),
        _ => println!("heelo")
    };

}

fn arrays_loops()
{
    let arr : [i32; 5] = [1, 2, 3, 4, 5];
    let mut count: usize = 0;

    loop
    {
        
        if count == arr.len()
        {
            break;
        }

        println!("{}", arr[count]);
        count += 1;

    }
    
    count = 0;

    while count < arr.len()
    {
        println!{"{}", arr[count]};
        count += 1;
    }

    for i in arr.iter()
    {
        println!("{}", i);
    }
}