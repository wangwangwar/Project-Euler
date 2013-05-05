#!/usr/bin/env python

sum = 0L
for line in open('q13.dat').readlines():
    sum = sum + int(line)

print str(sum)[:10]
