def main():
  s = int(input())
  if s >= 42:
    s+=1
  s = str(s).zfill(3)
  print("AGC"+s)

if __name__ == '__main__':
  main()


