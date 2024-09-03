def main():
    n = int(input())
    ls = []
    rs = []
    for _ in range(n):
        a,s = input().split()
        a = int(a)
        if s == 'R':
            rs.append(a)
        else:
            ls.append(a)
    lp = 0
    rp = 0
    ans = 0
    
    if len(ls) != 0:
        for i in range(len(ls)):
            if i == 0:
                lp = ls[i]
            else:
                ans += abs(ls[i]-lp)
                lp = ls[i]
    if len(rs) != 0:
        for i in range(len(rs)):
            if i == 0:
                rp = rs[i]
            else:
                ans += abs(rs[i]-rp)
                rp = rs[i]
    print(ans)
if __name__ == "__main__":
    main()