def main():
    n,d = map(int,input().split())
    s = input()
    for c in s:
        if c == '.':
            d+=1
    
    print(d)

if __name__ == "__main__":
    main()