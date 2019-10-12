import unittest
from stack import Stack


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


if __name__ == "__main__":
    unittest.main()
