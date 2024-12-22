def main():
    n = int(input())
    h = list(map(int,input().split()))
    ans = 0
    for d in range(1,3000):
        seen = [False]*n
        for i in range(n):
            if seen[i]:
                continue
            cnt = 1
            j = i+d
            while j < n and h[j] == h[i]:
                cnt+=1
                j += d
            
            ans = max(cnt,ans)
    
    print(ans)

if __name__ == "__main__":
    main()