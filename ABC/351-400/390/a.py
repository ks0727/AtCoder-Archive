def main():
    a = list(map(int,input().split()))
    for i in range(4):
        a[i+1],a[i] = a[i],a[i+1]
        for j in range(4):
            if a[j] > a[j+1]:
                break
            
            if j == 3:
                print("Yes")
                return
        a[i+1],a[i] = a[i],a[i+1]
    
    print("No")

if __name__ == "__main__":
    main()