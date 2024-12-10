def main():
    n = int(input())
    M = int(2e6+5)
    isp = [True]*M
    isp[0] = isp[1] = False
    for i in range(M):
        if not isp[i]:
            continue
        for j in range(i*2,M,i):
            isp[j] = False

    ps = []
    for i in range(M):
        if isp[i]:
            ps.append(i)

    ans = 0
    for p in ps:
        if p**8 <= n:
            ans += 1
        else:
            break
    
    r = len(ps)-1
    for l in range(len(ps)):
        while r >= l and ps[r]*ps[r]*ps[l]*ps[l] > n:
            r -= 1
        ans += r-l
        if r <= l:
            break

    print(ans)

if __name__ == "__main__":
    main()