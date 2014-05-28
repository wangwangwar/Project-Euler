#!/usr/bin/env python3
import unittest


def fib_gen():
    a = 1
    b = 1
    yield a
    yield b
    while True:
        b = a + b
        a = b - a
        yield b


def main():
    count = 0
    for nxt in fib_gen():
        count += 1
        if len(str(nxt)) >= 1000:
            return count


class Test(unittest.TestCase):

    def test_fib(self):
        fib = fib_gen()
        self.assertEqual(next(fib), 1)
        self.assertEqual(next(fib), 1)
        self.assertEqual(next(fib), 2)
        self.assertEqual(next(fib), 3)
        self.assertEqual(next(fib), 5)


if __name__ == '__main__':
    print(main())
    unittest.main()
