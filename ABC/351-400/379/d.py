from collections import defaultdict

q = int(input())
d = {}
for _ in range(q):
    xs = list(map(int,input().split()))
    if xs[0] == 1:
        if 0 in d:
            d[0]+=1
        else:
            d[0]= 1
    elif xs[0] == 2:
        t = xs[1]
        nd = {}
        for key,val in d.items():
            nd[key-t] = val
        
        d = nd.copy()
        
    else:
        h = xs[1]
        rm = []
        ans = 0
        for k in d.keys():
            if -k < h:
                break
            rm.append(k)
            ans += d[k]
        
        for x in rm:
            del(d[x])
        
        print(ans)
    d = dict(sorted(d.items()))

