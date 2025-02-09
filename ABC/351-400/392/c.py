def main():
    n = int(input())
    p = list(map(int,input().split()))
    q = list(map(int,input().split()))
    
    p = [x-1 for x in p]
    q = [x-1 for x in q]
    
    to = [-1]*n
    for i in range(n):
        to[q[i]] = p[i]
        
    ans = []
    for i in range(n):
        ans.append(q[to[i]])

    ans = [str(x+1) for x in ans]
    s = " ".join(ans)
    
    print(s)
if __name__ == "__main__":
    main()