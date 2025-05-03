def main():
  t = input()
  u = input()
  for i in range(len(t)-len(u)+1):
    ok = True
    for j in range(len(u)):
      if t[i+j] != u[j] and t[i+j] != '?':
        ok = False
    if ok:
      print("Yes")
      exit(0)
  print("No")

if __name__ == '__main__':
  main()


