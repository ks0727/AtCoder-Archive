def main():
    n = int(input())
    tv = []
    for i in range(n):
        t,v = map(int,input().split())
        tv.append((t,v))
    
    ans = 0
    prev = 0
    for i in range(n):
        t,v = tv[i]
        ans -= t-prev
        if ans < 0:
            ans = 0
        prev = t
        ans += v
    
    print(ans)



if __name__ == "__main__":
    main()