def __main__():
    n = int(input())
    ans = 0
    def f(x):
        res = 0
        for i in range(1,int(x**0.5)+1):
            if x%i != 0:
                continue
            if i == x//i:
                res +=1
            else:
                res +=2
        return res
    
    for x in range(1,n):
        ans += f(x)*f(n-x)    
    print(ans)

__main__()
