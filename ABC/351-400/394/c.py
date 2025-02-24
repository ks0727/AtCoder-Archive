def main():
    s = list(input())
    for i in range(len(s)-2,-1,-1):
        if s[i]+s[i+1] == "WA":
            s[i] = "A"
            s[i+1] = "C"
    
    s = ''.join(s)
    print(s)

if __name__ == "__main__":
    main()