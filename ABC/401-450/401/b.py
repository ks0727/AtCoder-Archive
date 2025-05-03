def main():
  n = int(input())
  login = False
  ans = 0
  for i in range(n):
    s = input()
    if s == "login":
      login = True
    elif s == "logout":
      login = False
    elif s == "private" and not login:
      ans += 1
  print(ans)
if __name__ == '__main__':
  main()


