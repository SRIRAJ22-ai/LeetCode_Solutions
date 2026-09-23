t = int(input())

for _ in range(t):
    n, k = map(int, input().split())

    work = 0
    minutes = 0

    while work < n:
        minutes += 1

        if minutes % k != 0:
            work += 1

    print(minutes)