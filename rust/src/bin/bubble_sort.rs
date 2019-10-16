// Bubble sorting a user-provided array
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

    arr = bubble_sort(&mut arr);

    println!("Sorted array:");
    for i in arr.iter() {
        println!("{}", i);
    }
}

fn bubble_sort(array: &mut [i32; ARRAY_SIZE]) -> [i32; ARRAY_SIZE] {
    for i in 0..(ARRAY_SIZE - 1) {
        for j in 0..(ARRAY_SIZE - i - 1) {
            if array[j] > array[j + 1] {
                array.swap(j, j + 1);
            }
        }
    }
    array.to_owned()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_bubble_sort() {
        let mut arr = [1, 9, 5, 7, 8, 6, 3, 4, 2, 0];

        arr = bubble_sort(&mut arr);

        assert_eq!(arr[0], 0);
        assert_ne!(arr[0], 1);
        assert_eq!(arr[9], 9);
    }
}
