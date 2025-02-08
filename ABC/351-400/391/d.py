import heapq
def main():
    n,w = map(int,input().split())
    xy = []
    INF = 1001001001
    fall = [INF]*n
    blocks = [[] for _ in range(w)]
    for i in range(n):
        x,y = map(int,input().split())
        y-=1
        x-=1
        xy.append((x,y,i))
    
    for i in range(n):
        x,y, idx = xy[i]
        heapq.heappush(blocks[x],(y,idx))

    #for i in range(w):
        # print("-"*100)
        # print(f"block {i} : ")
        # for x in blocks[i]:
        #     print(x)
    keep = True
    while keep:
        mx = -1
        bs = []
        for i in range(w):
            if len(blocks[i]) == 0:
                keep = False
                break
            else:
                y,idx = heapq.heappop(blocks[i])
                mx = max(y,mx)
                bs.append(idx)
        
        if not keep:
            break
        for b in bs:
            fall[b] = mx

    q = int(input())
    for _ in range(q):
        t,a = map(int,input().split())
        a-=1
        if fall[a] < t:
            print("No")
        else:
            print("Yes")

if __name__ == "__main__":
    main()