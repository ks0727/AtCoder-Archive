def main():
    s = input()
    a = [c for c in s]
    a = sorted(a)
    na = "".join(a)
    if na == "ABC":
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()