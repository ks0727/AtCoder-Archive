def main():
  s = input()
  t = input()
  if (s == "#." and t == ".#") or (s == ".#" and t == "#."):
    print("No")
  else:
    print("Yes")  
if __name__ == '__main__':
  main()


