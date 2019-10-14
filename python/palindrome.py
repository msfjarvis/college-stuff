def palindrome(word: str) -> bool:
    return word.lower() == word.lower()[::-1]


def main():
    tocheck = input("Enter a word ")
    if palindrome(tocheck):
        print(tocheck, "is a palindrome")


if __name__ == "__main__":
    main()
