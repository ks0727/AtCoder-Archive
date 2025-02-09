def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    a = [x-1 for x in a]
    exist = [False]*n
    for i in range(m):
        exist[a[i]] = True
    
    ans = []
    
    for i in range(n):
        if not exist[i]:
            ans.append(i+1)
    
    
    ans = [str(x) for x in ans]
    s = " ".join(ans)
    print(len(ans))
    print(s)

if __name__ == "__main__":
    main()