def main():
    n = int(input())
    ans = [list('.'*n) for _ in range(n)]
    
    for i in range(n):
        j = n-i-1
        if i>j:
            continue
        if i%2 == 0:
            for ii in range(i,j+1):
                for jj in range(i,j+1):
                    ans[ii][jj] = '#'
        else:
            for ii in range(i,j+1):
                for jj in range(i,j+1):
                    ans[ii][jj] = '.'
    
    for i in range(n):
        print("".join(ans[i]))

if __name__ == "__main__":
    main()