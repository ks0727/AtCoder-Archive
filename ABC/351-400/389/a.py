def main():
    s = input()
    a = s[0]
    b = s[2]
    a = ord(a) - ord('0')
    b = ord(b) - ord('0')
    print(a*b)

if __name__ == "__main__":
    main()