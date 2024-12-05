def main():
    n,d = map(int,input().split())
    s = list(input())
    
    for i in range(n-1,-1,-1):
        if d > 0 and s[i] == '@':
            s[i] = '.'
            d -= 1
    
    print(''.join(s))
            

if __name__ == "__main__":
    main()