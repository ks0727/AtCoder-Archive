def main():
  x = input()
  a = int(x.split('.')[0])
  b = int(x.split('.')[-1])
  if a >= 38:
    print(1)
  elif a == 37 and b >= 5:
    print(2)
  else:
    print(3)
    
if __name__ == '__main__':
  main()


