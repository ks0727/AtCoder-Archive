def main():
  l,r = map(int,input().split())
  l-=1; r-=1;
  s = input()
  n = len(s)
  t = s[::-1]
  s = s[:l] + t[n-r-1:n-l] + s[r+1:]
  print(s)

if __name__ == '__main__':
  main()


