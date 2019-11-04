#[macro_use] extern crate dmoj;

fn main() {
    let (width, height) = scan!(i16, i16);
    let size = scan!(i16);
    let l = width / size;
    let h = height / size;
    println!("{}", l * h);
}