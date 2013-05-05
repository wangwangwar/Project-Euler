#!/usr/bin/env python

n = 2 ** 1000
sum = 0
for digit in str(n):
    sum = sum + int(digit)

print(sum)
