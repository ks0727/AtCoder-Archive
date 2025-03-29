def main():
    n = int(input())
    a = list(map(int,input().split()))
    
    M = int(1e6+5)
    arr = [[] for _ in range(M)]
    
    for i in range(len(a)):
        arr[a[i]].append(i)
    
    ans = int(1e9)
    for ar in arr:
        if len(ar) < 2:
            continue
        for i in range(len(ar)-1):
            ans = min(ans,ar[i+1]-ar[i]+1)
    
    if ans == int(1e9):
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    main()