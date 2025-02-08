def main():
    n,q = map(int,input().split())
    pos = list(range(n))
    cnt = [1]*n
    multi = set([])
    for _ in range(q):
        qi = list(map(int,input().split()))
        t = qi[0]
        if t == 1:
            p,h = qi[1:]
            p -= 1
            h -= 1
            cnt[pos[p]] -= 1
            if cnt[pos[p]] == 1:
                multi.discard(pos[p])
            cnt[h] += 1
            pos[p] = h
            if cnt[h] == 2:
                multi.add(h)
        else:
            print(len(multi))
        
        # si = [str(x) for x in multi]
        # s = ' '.join(si)
        # print(s)

if __name__ == "__main__":
    main()