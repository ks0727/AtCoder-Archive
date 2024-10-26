def main():
  a,b = map(int,input().split())
  while a > 0 and b > 0:
    na = a%10
    nb = b%10
    if na + nb >= 10:
      print("Hard")
      return
    a //= 10
    b //= 10

  print("Easy")
if __name__ == '__main__':
  main()


