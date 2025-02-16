def main():
    s,t = map(str,input().split())
    ans = 0
    if s == "sick" and t == "sick":
        ans = 1
    elif s == "sick" and t == "fine":
        ans = 2
    elif s == "fine" and t == "sick":
        ans = 3
    else:
        ans = 4
    print(ans)


if __name__ == "__main__":
    main()