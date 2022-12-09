use std::{io};

struct shape
{
    area: f32,
    length: f32
}

trait allShapes
{
    fn new(area: f32, length: f32) -> Self;
    fn getArea(&self) -> f32;
    fn getLength(&self) -> f32;
}

fn main() 
{
    //io_ops();
    //datatypes();
    //condition_ops();
    //arrays_loops();
    //tuples();
    //vectors();
    //enums();
    //structs();
    
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

fn tuples()
{
    let mut tup : (i32, String, f32) = (12, "heelo".to_string(), 3.45);
    
    println!("{}{}", tup.0, tup.1);
}

fn vectors()
{
    let str : String = String::from("a b c e d g w ");

    let mut vector : Vec<char> = str.chars().collect();

    vector.sort();
    vector.dedup();

    for i in vector
    {
        println!("{}", i);
    }

    let vec2 = vec![1, 2, 3, 4];
    let vec3: Vec<String> = Vec::new();
}

fn enums()
{
    enum Days
    {
        Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
    }

    impl Days
    {
        fn isWorkDay(&self) -> bool
        {
            match self
            {
                Days::Saturday | Days::Sunday => false,
                _ => true
            }
        }    
    }

    let day: Days = Days::Monday;

    println!("{}", day.isWorkDay());
}

fn ownership()
{
    let str1: String = String::from("Heeki");

    //let str2: String = str1; str2 borrowed from str1.

    let str2: String = str1.clone(); //just copy

    println!("{}{}", str1, str2);
}

fn structs()
{
    let rec: shape = shape::new(12.34, 34.21);

    println!("{}", rec.getArea());
    println!("{}", rec.getLength());

}

impl allShapes for shape // implementation of trait allShapes to struct shape
{

    fn new(area: f32, length: f32) -> shape
    {
        return shape { area, length};
    }

    fn getArea(&self) -> f32 
    {
        return self.area;
    }

    fn getLength(&self) -> f32 
    {
        return self.length;
    }
}