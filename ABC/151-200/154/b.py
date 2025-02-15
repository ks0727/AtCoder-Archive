def isp(x):
  t = x.copy()
  t = t[::-1]
  for i in range(len(t)):
    if t[i] != x[i]:
     return False
  return True 

def main():
  s = list(input());
  n = int(len(s))
  if not isp(s) or not isp(s[:n//2]) or not isp(s[n//2+1:]):
    print("No")
  else:
    print("Yes")

    
if __name__ == '__main__':
  main()


