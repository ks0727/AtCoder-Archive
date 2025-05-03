def main():
  s = list(input())
  ans = []
  for c in s:
    if  'A' <= c <= 'Z':
      ans.append(c)

  ans = ''.join(ans)
  print(ans)

if __name__ == '__main__':
  main()


