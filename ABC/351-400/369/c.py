def main():
    n = int(input())
    a = list(map(int,input().split()))
    
    d = []
    for i in range(n-1):
        d.append(a[i+1]-a[i])
    
    p = [(-1001001001,0)]
    for i in range(n-1):
        prev,pc = p[-1]
        if prev == d[i]:
            p.pop()
            p.append((prev,pc+1))
        else:
            p.append((d[i],1))
    ans = n
    for v,cnt in p:
        ans += cnt*(cnt+1)//2
    
    print(ans)

if __name__ == "__main__":
    main()