def palindrome(word: str) -> bool:
    return word.lower() == word.lower()[::-1]
