def main():
    s = input()
    ans = []
    for i in range(len(s)):
        if(s[i] == '-'):
            continue
        j = i+1
        while j<len(s) and s[j] == '-':
            j+=1
        j-=1
        ans.append(j-i)
    
    ans.pop(-1)
    ans = [str(x) for x in ans]
    ans = " ".join(ans)
    print(ans)

if __name__ == "__main__":
    main()