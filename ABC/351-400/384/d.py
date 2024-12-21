def main():
    n,s = map(int,input().split())
    a = list(map(int,input().split()))
    
    sum = 0
    for x in a:
        sum += x
    
    s %= sum

    b = a.copy()
    b = b+b
    r = 0
    now = 0
    for l in range(2*n):
        while r < 2*n and now + b[r] <= s:
            now += b[r]
            r += 1

        if now == s:
            print("Yes")
            exit()
        
        if r == l:
            r += 1
        else:
            now -= b[l]
    
    print("No")

if __name__ == "__main__":
    main()