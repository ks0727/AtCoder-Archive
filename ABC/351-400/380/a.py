def main():
    s = input()
    cnt = {}
    for i in range(10):
        cnt[i] = 0
    for i in range(len(s)):
        cnt[ord(s[i])-ord('0')]+=1
    
    for i in range(1,4):
        if(cnt[i] != i):
            print("No")
            exit()
    
    print("Yes")

if __name__ == "__main__":
    main()