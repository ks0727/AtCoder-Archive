def main():
    n,m = map(int,input().split())
    st = set()
    ans = 0
    for _ in range(m):
        a,b = map(int,input().split())
        a-= 1; b -= 1
        if a > b:
            a,b = b,a
        if (a,b) in st or a == b:
            ans += 1
        else:
            st.add((a,b))
    
    print(ans)

if __name__ == "__main__":
    main()