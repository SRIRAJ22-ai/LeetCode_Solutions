T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    prefix = 0
    minimum_prefix = 0
    first_bad = -1

    for i in range(N):
        prefix += A[i]
        minimum_prefix = min(minimum_prefix, prefix)

        if prefix < 0 and first_bad == -1:
            first_bad = i

    if first_bad == -1:
        print("YES")
        continue

    possible = False

    for i in range(first_bad + 1):
        if A[i] <= minimum_prefix:
            possible = True
            break

    print("YES" if possible else "NO")