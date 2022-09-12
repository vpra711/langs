fn main() {
    // https://doc.rust-lang.org/std/primitive.str.html
    // primitive datatypes
    // scalar types - int, float, char, string, bool
    let x: u32 = 1234;
    let x1: i32 = 1234;
    // i8 to i128
    let y: f32 = 2.34;
    let y1: f64 = 2.3456; // f64 is default for floating point
    let x = "It will allocate datatype automatically if not specified";
    // and we can redefine variables 
    // by default rust variables are immutable
    // to define mutable variables put mut 
    let mut y: f64 = 7.8832;
    let c: char = 'A';
    let s: &str = "This is a string";

    println!("{}, {}, {}, {}, {}, {}", x, x1, y, y1, c, s);

    // compound types - tuple, arrays

    let mut tup:(i32, bool, f64) = (23, true, 2.345);
    print!("{:?}", tup);
    tup.0 = 45;
    println!("{:?}", tup);

    let mut arr: [i32; 5] = [1, 2, 3, 4, 5];
    println!("{:?}", arr[0]);
    println!("{:?}", arr);
    let mut arr: [i32; 5];
    // println!("{:?}", arr); unintialization error


}
