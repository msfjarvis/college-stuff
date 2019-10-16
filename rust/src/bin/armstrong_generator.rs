// List all the armstrong numbers between two given numbers
#[macro_use]
extern crate text_io;

use std::convert::TryInto;

#[allow(clippy::try_err)]
fn main() {
    println!("Enter lower limit for search");
    let min: i32 = read!();
    println!("Enter top limit for search");
    let max: i32 = read!();

    for num in min..=max {
        if check_armstrong(num) {
            println!("{}", num);
        }
    }
}

fn check_armstrong(n: i32) -> bool {
    let mut sum = 0;
    let mut temp = n;
    let mut remainder;
    let mut digits = 0;

    while temp != 0 {
        digits += 1;
        temp /= 10;
    }

    temp = n;

    while temp != 0 {
        remainder = (temp % 10).try_into().unwrap();
        sum += power(remainder, digits);
        temp /= 10;
    }

    n == sum
}

fn power(n: i32, r: i32) -> i32 {
    let mut p: i32 = 1;

    for _i in 1..=r {
        p *= n;
    }

    p
}

#[cfg(test)]
mod tests {

    use super::check_armstrong;

    #[test]
    fn test_armstrong_generator() {
        assert!(check_armstrong(153));
        assert!(!check_armstrong(200));
    }
}
