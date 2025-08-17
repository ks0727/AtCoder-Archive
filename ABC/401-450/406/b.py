def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    limit = 10 ** k
    ans = 1
    for ai in a:
        ans *= ai
        if ans >= limit:
            ans = 1

    print(ans)

if __name__ == "__main__":
    main()



