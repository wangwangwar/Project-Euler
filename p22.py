

def worth(word):
    sum = 0
    for c in word:
        sum += (ord(c) - ord('A') + 1)
    return sum


def total_score():
    sorted_words = None
    with open('names.txt', 'r') as f:
        line = f.readline()
        words = (map(lambda word: word.strip('"'), line.split(',')))
        sorted_words = sorted(words)

    sum = 0
    for i, word in enumerate(sorted_words):
        sum += (i + 1) * worth(word)

    return sum


if __name__ == '__main__':
    ts = total_score()
    print(ts)
