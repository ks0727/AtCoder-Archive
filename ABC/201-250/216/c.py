def main():
  n = int(input())
  s = []
  while n > 0:
    if n%2 == 0:
      n/=2
      s.append("B")
    else:
      n-=1
      s.append("A")
  s = "".join(reversed(s))
  print(s)
if __name__ == '__main__':
  main()


