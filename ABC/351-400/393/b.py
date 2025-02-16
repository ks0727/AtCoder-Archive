def main():
    s = list(input())
    n = len(s)
    ans = 0
    for d in range(1,n):
        for i in range(n):
            if s[i] != 'A':
                continue
            if i+2*d >= n:
                break
            if s[i]+s[i+d]+s[i+2*d] == "ABC":
                ans += 1
    print(ans)
    
if __name__ == "__main__":
    main()