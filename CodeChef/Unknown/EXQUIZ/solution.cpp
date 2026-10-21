t = int(input())

for _ in range(t):
    n, s = map(int, input().split())

    ans = -1

    for correct in range((s + 3) // 4, n + 1):
        wrong = 4 * correct - s

        if wrong >= 0 and correct + wrong <= n:
            ans = correct + wrong
            break

    print(ans)
