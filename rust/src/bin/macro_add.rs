// Counterpart of the recursion based addition program in C but with Rust
// macros instead, because the end goal of this entire undertaking is learning
// new things :)

macro_rules! add_all {
    ($($x:expr), *) => {{
        let mut result = 0;
        $(result += $x;)*
        result
    }}
}

fn main() {
    println!("{}", add_all!(1, 2, 3, 4, 5));
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_add_all_macro() {
        assert_eq!(add_all!(0, 0, 0, 0, 0), 0);
        assert_ne!(add_all!(1, 2, 3, 4, 5), 0);
        assert_eq!(
            add_all!(add_all!(1, 2, 3, 4, 5), add_all!(6, 7, 8, 9, 10)),
            55
        );
    }
}
