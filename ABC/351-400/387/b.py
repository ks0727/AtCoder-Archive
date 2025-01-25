def main():
    x = int(input())
    ans = 0
    for i in range(10):
        for j in range(10):
            if(i*j == x):
                continue
            ans += i*j
            
    print(ans)

if __name__ == "__main__":
    main()