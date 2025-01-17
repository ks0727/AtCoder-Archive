def main(n, a):
    i, j = 0, 1
    count = 0

    while i < n and j < n:
        if a[i] * 2 <= a[j]:
            count += 1
            i += 1
        j += 1

    return count

n = int(input())
a = list(map(int, input().split()))

print(main(n, a))
