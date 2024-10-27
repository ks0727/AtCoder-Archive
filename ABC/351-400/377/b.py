def main():
    s = [input() for _ in range(8)]
    ans = 0
    for i in range(8):
        for j in range(8):
            ok = True
            for ii in range(8):
                if s[ii][j] == '#':
                    ok = False

            for jj in range(8):
                if s[i][jj] == '#':
                    ok = False

            if ok:
                ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()