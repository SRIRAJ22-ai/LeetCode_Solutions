t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort(reverse=True)

    if k >= n - 1:
        print(sum(a))
    else:
        print(sum(a[:k + 1]))
