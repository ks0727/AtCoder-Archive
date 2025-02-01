def main():
  s = input()
  t = s[-3:]
  t = int(t)
  if t > 0 and t <= 349 and t != 316:
    if s[:3] == "ABC":
      print("Yes")
      return
    else:
      print("No")
      return
  else:
    print("No")
    return
if __name__ == '__main__':
  main()


