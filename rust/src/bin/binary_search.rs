// Efficient binary searching algorithm
#[macro_use]
extern crate text_io;

const ARRAY_SIZE: usize = 10;

#[allow(clippy::try_err, clippy::needless_range_loop)]
fn main() {
    let mut arr = [0 as i32; ARRAY_SIZE];

    println!("Enter {} elements for array", ARRAY_SIZE);
    for i in 0..ARRAY_SIZE {
        arr[i] = read!();
    }

    println!("Enter number to find");
    let search: i32 = read!();

    binary_search(&arr, search);
}

fn binary_search(array: &[i32; ARRAY_SIZE], item: i32) -> bool {
    let (mut first, mut last) = (0, ARRAY_SIZE - 1);
    let mut middle = (first + last) / 2;

    while first <= last {
        if array[middle] < item {
            first = middle + 1;
        } else if array[middle] == item {
            println!("{} found at index {}", item, middle);
            break;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if first > last {
        println!("{} was not found in the list", item);
        return false;
    }
    true
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::convert::TryInto;

    #[test]
    fn test_binary_search() {
        let mut arr = [0 as i32; ARRAY_SIZE];

        for i in 0..ARRAY_SIZE {
            arr[i] = i.try_into().unwrap();
        }
        assert!(binary_search(&arr, 9));
        assert!(!binary_search(&arr, 100));
    }
}
