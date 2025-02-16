def main():
    n = int(input())
    s = list(input())
    a = []
    for i in range(n):
        a.append(1 if s[i] == '1' else 0)
    sl = [0]*(n+1)
    sr = [0]*(n+1)
    for i in range(n):
        sl[i+1] = sl[i]+a[i]
    for i in range(n-1,-1,-1):
        sr[i] = sr[i+1]+a[i]
    ans = 0
    for i in range(n):
        if s[i] == '0':
            ans += min(sl[i+1],sr[i])
    print(ans)
if __name__ == "__main__":
    main()