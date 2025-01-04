def main():
  a = list(map(int,input().split()))
  now = 1
  ans = 0
  for x in a:
    if x == 1:
      ans += now
    now *= 2

  print(ans)

if __name__ == '__main__':
  main()


