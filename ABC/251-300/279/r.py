from collections import defaultdict
def main():
  h,w = map(int,input().split())
  s = [list(input()) for _ in range(h)]
  t = [list(input()) for _ in range(h)]
  ns = []
  nt = []
  for i in range(w):
    cs = ""
    ts = ""
    for j in range(h):
      cs += s[j][i]
      ts += t[j][i]
    ns.append(cs)
    nt.append(ts)
      
  ns = sorted(ns)
  nt = sorted(nt)
  if ns == nt:
    print("Yes")
  else:
    print("No") 


if __name__ == '__main__':
  main()


