def main():
  s = list(input())
  y = int(s[-1])
  s.pop()
  s.pop()
  if y <= 2:
    print(''.join(s)+'-')
  elif y<= 6:
    print(''.join(s))
  else:
    print(''.join(s)+'+')

if __name__ == '__main__':
  main()


