t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()

    ans = max(a[-1], a[0] + a[1])
    print(ans)
