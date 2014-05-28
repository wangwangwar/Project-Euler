#!/usr/bin/env python3


def get_next_permu(num_list):
    n = len(num_list)
    j = n - 2

    while num_list[j] >= num_list[j + 1] and j > 0:
        j = j - 1

    if j < 0:
        raise

    i = n - 1
    while num_list[j] >= num_list[i]:
        i = i - 1

    num_list[j], num_list[i] = num_list[i], num_list[j]

    l = j + 1
    r = n - 1
    while l < r:
        num_list[l], num_list[r] = num_list[r], num_list[l]
        l = l + 1
        r = r - 1

    return num_list


if __name__ == '__main__':
    permu = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for i in range(1, 1000000):
        permu = get_next_permu(permu)

    print(permu)
