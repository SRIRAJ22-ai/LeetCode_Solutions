t = int(input())

for _ in range(t):
    n, d = map(int, input().split())

    s = str(n)
    forbidden = str(d)

    while forbidden in s:
        i = s.index(forbidden)

        prefix = int(s[:i + 1]) + 1
        s = str(prefix)

        if d == 0:
            s += '1' * (len(str(n)) - i - 1)
        else:
            s += '0' * (len(str(n)) - i - 1)

    print(s)
