#[macro_use]
extern crate text_io;

use std::io::{self, Write};

pub const ARRAY_SIZE: usize = 5;

fn add_matrices(
    m1: &[[i32; ARRAY_SIZE]; ARRAY_SIZE],
    m2: &[[i32; ARRAY_SIZE]; ARRAY_SIZE],
) -> [[i32; ARRAY_SIZE]; ARRAY_SIZE] {
    let mut res = [[0 as i32; ARRAY_SIZE]; ARRAY_SIZE];
    for i in 0..ARRAY_SIZE {
        for j in 0..ARRAY_SIZE {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
    res
}

#[allow(clippy::try_err, clippy::needless_range_loop)]
fn main() {
    let mut first = [[0 as i32; ARRAY_SIZE]; ARRAY_SIZE];
    let mut second = [[0 as i32; ARRAY_SIZE]; ARRAY_SIZE];

    println!("Enter the elements of the first array");
    for i in 0..ARRAY_SIZE {
        for j in 0..ARRAY_SIZE {
            print!("Enter value of first[{}][{}]: ", i, j);
            io::stdout().flush().unwrap();
            first[i][j] = read!();
        }
    }

    println!("Enter the elements of the second array");
    for i in 0..ARRAY_SIZE {
        for j in 0..ARRAY_SIZE {
            print!("Enter value of second[{}][{}]: ", i, j);
            io::stdout().flush().unwrap();
            second[i][j] = read!();
        }
    }

    println!("Output matrix is: {:?}", add_matrices(&first, &second));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_matrix_addition() {
        let mut first = [[0 as i32; ARRAY_SIZE]; ARRAY_SIZE];
        let mut second = [[0 as i32; ARRAY_SIZE]; ARRAY_SIZE];
        let mut idx: i32 = 0;

        for i in 0..ARRAY_SIZE {
            for j in 0..ARRAY_SIZE {
                first[i][j] = idx;
                second[i][j] = idx + 1;
                idx += 1;
            }
        }

        let res = add_matrices(&first, &second);
        assert_eq!(res[0][0], first[0][0] + second[0][0]);
        assert_eq!(res[4][4], 49);

        for i in 0..ARRAY_SIZE {
            for j in 0..ARRAY_SIZE {
                assert!(res[i][j] != 0);
            }
        }
    }
}
