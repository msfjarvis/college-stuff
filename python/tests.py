import unittest
from stack import Stack
import armstrong, dectobin, factorial, fibonacci, palindrome, calc


class StackTest(unittest.TestCase):
    def setUp(self):
        pass

    def test_stack(self):
        stack = Stack(100)
        stack.push(1)
        self.assertEqual(stack.peek(), 1)
        print(f"{stack.pop()} popped from stack")
        self.assertNotEqual(stack.peek(), 1)
        for i in range(0, stack.size + 1):
            stack.push(i)
        self.assertEqual(stack.peek(), stack.size - 1)


class ArmstrongTest(unittest.TestCase):
    def test_armstrong(self):
        self.assertEqual(armstrong.is_arm(54748), True)
        self.assertEqual(armstrong.is_arm(6969), False)


class DectobinTest(unittest.TestCase):
    def test_dectobin(self):
        self.assertEqual(dectobin.dectobin(69), 1000101)
        self.assertEqual(dectobin.dectobin(420), 110100100)


class FactorialTest(unittest.TestCase):
    def test_factorial(self):
        self.assertEqual(factorial.facto(5), 120)
        self.assertEqual(factorial.facto(10), 3628800)


class FibonacciTest(unittest.TestCase):
    def test_fibonacci(self):
        self.assertEqual(fibonacci.fibo(5), [1, 1, 2, 3, 5])
        self.assertEqual(fibonacci.fibo(10), [1, 1, 2, 3, 5, 8, 13, 21, 34, 55])


class PalindromeTest(unittest.TestCase):
    def test_fibonacci(self):
        self.assertEqual(palindrome.palindrome("6969"), False)
        self.assertEqual(palindrome.palindrome("Malayalam"), True)


class TestCalc(unittest.TestCase):
    def test_add(self):
        self.assertEqual(calc.add(10, 5), 15)
        self.assertEqual(calc.add(-1, 1), 0)
        self.assertEqual(calc.add(-1, -1), -2)

    def test_subtract(self):
        self.assertEqual(calc.subtract(10, 5), 5)
        self.assertEqual(calc.subtract(-1, 1), -2)
        self.assertEqual(calc.subtract(-1, -1), 0)

    def test_multiply(self):
        self.assertEqual(calc.multiply(10, 5), 50)
        self.assertEqual(calc.multiply(-1, 1), -1)
        self.assertEqual(calc.multiply(-1, -1), 1)

    def test_divide(self):
        self.assertEqual(calc.divide(10, 5), 2)
        self.assertEqual(calc.divide(-1, 1), -1)
        self.assertEqual(calc.divide(-1, -1), 1)
        self.assertEqual(calc.divide(5, 2), 2.5)

        with self.assertRaises(ValueError):
            calc.divide(10, 0)

    def test_facto(self):
        self.assertEqual(calc.facto(5), 120)
        self.assertEqual(calc.facto(10), 3628800)


if __name__ == "__main__":
    unittest.main()
