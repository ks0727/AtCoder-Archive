import re
def main():
  s = input()
  if re.fullmatch("^(oxx)*(o|ox|oxx)$",s):
    print("Yes")
  elif re.fullmatch("^(xxo)*(x|xx|xxo)$",s):
    print("Yes")
  elif re.fullmatch("^(xox)*(x|xo|xox)$",s):
    print("Yes")
  else:
    print("No")
if __name__ == '__main__':
  main()


