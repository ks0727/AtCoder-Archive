def main():
  s = input()
  t = ""
  for _ in range(10):
    t += "oxx"

  for i in range(3):
    if t[i:i+len(s)] == s:
      print("Yes")
      exit()

  print("No")

if __name__ == '__main__':
  main()


