def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    b = [(x,i) for i,x in enumerate(b)]
    b = sorted(b,reverse=True)
    now = 0
    ans = [-1]*m
    
    for i in range(n):
        while now < m and a[i] <= b[now][0]:
            ans[b[now][1]] = i+1
            now += 1
        
    
    for x in ans:
        print(x)

if __name__ == "__main__":
    main()