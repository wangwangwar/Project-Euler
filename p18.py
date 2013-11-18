#!/usr/bin/python
"""Euler Project Problem 18. It can also solve problem 67."""

import pprint


def map_func(s):
    return {'num': int(s),
            'bigger': None,
            'sum': int(s)}

num_tree = []
with open('p18.txt', 'r') as f:
#with open('p67.txt', 'r') as f:
    for line in f:
        num_tree.append(list(map(map_func, line.split())))

    """From the last 2 level of *number tree*, we compare each node's left
    child and right child, choose the bigger one, sum it with node itself,
    and store in a dict such as:
        {
        'num': 71,
        'choice': 'left',
        'sum': 137
        }
    Then replace the node number with this dict.
    """
    for l in range(len(num_tree) - 2, -1, -1):
        for n in range(len(num_tree[l])):
            if num_tree[l + 1][n]['sum'] > num_tree[l + 1][n + 1]['sum']:
                num_tree[l][n] = {'num': num_tree[l][n]['num'],
                                  'bigger': 'left',
                                  'sum': num_tree[l][n]['num'] +
                                  num_tree[l + 1][n]['sum']
                                  }
            else:
                num_tree[l][n] = {'num': n,
                                  'bigger': 'right',
                                  'sum': num_tree[l][n]['num'] +
                                  num_tree[l + 1][n + 1]['sum']
                                  }

    pprint.pprint(num_tree[0][0]['sum'])
