def main():
    x = int(input())
    idx = 1
    now = 1
    while True:
        now *= idx
        if now == x:
            print(idx)
            break
        idx+=1
    

if __name__ == "__main__":
    main()