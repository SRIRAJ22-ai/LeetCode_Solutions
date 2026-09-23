t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    C = list(map(int, input().split()))

    ans = float('inf')

    for i in range(n):
        for j in range(i + 1, n):

            if i - k > 0:
                continue

            if j + k < n - 1:
                continue

            if j - i > 2 * k + 1:
                continue

            ans = min(ans, C[i] + C[j])

    if ans == float('inf'):
        print(-1)
    else:
        print(ans)