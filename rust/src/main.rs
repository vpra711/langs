use std::{io, thread, time::Duration};
mod games;
use crate::games::game::Details;

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
    //mods();
    //auto_functions();
    //pointers();
    //threads();    
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

fn mods()
{
    let game_name: String = "God of War".to_string();
    let players: i32 = 1;
    let difficulty: String = "god of war".to_string();
    let mut game1: Details = Details::new(game_name, players, difficulty);

    game1.change_difficulty("Normal");
    println!("{}", game1.get_difficult());

    game1.change_difficulty("God of war");
    println!("{}", game1.get_difficult());

}

fn auto_functions()
{

    //closures
    //can access outside variables
    //can pass to functions

    let closure = |no: i32|
    {
        return no > 20;
    };

    println!("result: {}", closure(23));

    fn fun<T>(a: i32, b: i32, func: T) -> i32
    where T: Fn(i32, i32) -> i32
    {
        func(a, b)
    }

    let mul = |a: i32, b: i32| -> i32 {return a * b};

    println!("mul of 15 and 23 is: {}", fun(15, 23, mul));
}

fn pointers()
{
    //box pointers

    struct Node
    {
        pub data: i32,
        pub next: Box<Node>
    }

    // impl Node
    // {
    //     pub fn new(data: i32) -> Self
    //     {
    //         return Node {data: data, next: Box::new(None)}
    //     }

    //     pub fn Next(mut self, node: Node) -> Self
    //     {
    //         self.next = Box::new(node);
    //         return self
    //     }
    // }

    // let mut list = Node::new(12).Next(Node::new(23));

    // println!("first in list: {}", list.data);

    // list = list.next;

    // println!("second in list: {}", list.;



}

fn threads()
{
    //threads

    let thread1Handler = thread::spawn(||
    {
        for i in 1..20
        {
            println!("t1 thread: {}", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    for i in 1..20
    {
        println!("main thread: {}", i);
        thread::sleep(Duration::from_millis(1));
    }

    thread1Handler.join();
    
}