def palindrome(word: str) -> bool:
    return word == word[::-1]


tocheck = input("Enter a word ")
if palindrome(tocheck):
    print(tocheck, "is a palindrome")
