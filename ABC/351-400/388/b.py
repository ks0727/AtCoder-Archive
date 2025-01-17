def main():
    n,d = map(int,input().split())
    tl = []
    for i in range(n):
        t,l = map(int,input().split())
        tl.append((t,l))

    for k in range(1,d+1):
        ans = 0
        for t,l in tl:
            ans = max(ans,(l+k)*t)
        
        print(ans)

if __name__ == "__main__":
    main()