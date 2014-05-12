#!/usr/bin/env python3
#-*- coding:utf-8 -*-
import unittest


def divisor_gen(n):
    for i in range(1, int(n / 2) + 1):
        if n % i == 0:
            yield i


def d(n):
    s = 0
    for d in divisor_gen(n):
        s += d
    return s


class Test(unittest.TestCase):

    def test_divisor_gen(self):
        n = 100
        gen = divisor_gen(n)
        self.assertEqual(next(gen), 1)
        self.assertEqual(next(gen), 2)
        self.assertEqual(next(gen), 4)
        self.assertEqual(next(gen), 5)
        self.assertEqual(next(gen), 10)
        self.assertEqual(next(gen), 20)
        self.assertEqual(next(gen), 25)
        self.assertEqual(next(gen), 50)
        self.assertRaises(StopIteration, next, gen)

    def test_d(self):
        n = 220
        self.assertEqual(d(n), 284)


def main():
    s = 0
    for i in range(1, 10000):
        if d(i) != i and d(d(i)) == i:
            s += i
    print(s)


if __name__ == '__main__':
    main()
    unittest.main()
