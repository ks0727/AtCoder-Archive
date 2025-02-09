def main():
    n = int(input())
    ks = []
    arr = []
    ps = []
    for _ in range(n):
        ka = list(map(int,input().split()))
        k = ka[0]
        a = ka[1:]
        a = sorted(a)
        p = []
        for i in range(len(a)):
            if len(p) == 0:
                p.append((a[i],1))
            else:
                if p[-1][0] == a[i]:
                    aLast,cnt = p[-1]
                    p.pop(-1)
                    p.append((aLast,cnt+1))
                else:
                    p.append((a[i],1))

        ks.append(k)
        ps.append(p)
    ans = 0
    for i in range(n):
        for j in range(i+1,n):
            p1 = ps[i]
            p2 = ps[j]
            now = 0
            cur = 0
            for val,cnt in p2:
                while now < len(p1) and p1[now][0] < val:
                    now+=1
                if now < len(p1) and val == p1[now][0]:
                    #print(f"ok : {i},{j},{val}")
                    #print("calculated",cnt,len(),p1[now][1],len(p1))
                    cur += cnt/ks[i]*p1[now][1]/ks[j]
            ans = max(ans,cur)
    
    print(f"{ans}")

if __name__ == "__main__":
    main()