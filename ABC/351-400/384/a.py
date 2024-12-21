def main():
    nc = list(input().split())
    n = nc[0]
    c1,c2 = nc[1],nc[2]
    s = list(input())
    for i in range(len(s)):
        if s[i] != c1:
            s[i] = c2
    
    s = ''.join(s)
    print(s)

if __name__ == "__main__":
    main()