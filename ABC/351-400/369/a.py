def main():
    a,b = map(int,input().split())
    ans = 0
    for i in range(-300,300):
        arr = list((a,b,i))
        arr = sorted(arr)
        if arr[1]*2 == arr[0]+arr[2]:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()