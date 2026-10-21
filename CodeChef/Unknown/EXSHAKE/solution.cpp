t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()

    total = 0
    count = 0

    for people in a:
        total += people
        handshakes = total * (total - 1) // 2

        if handshakes <= m:
            count += 1
        else:
            break

    print(count)
