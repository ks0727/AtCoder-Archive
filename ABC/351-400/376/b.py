def f(n,s,t,x): # s->tでの移動のコストを求める
  if s > t: #s < tとする
    s,t = t,s
  if s<x<t:
    return n-(t-s)
  return t-s

def main():
  n,q = map(int,input().split())
  l,r = 0,1
  ans = 0
  HT = [input().split() for _ in range(q)]
  for h,t in HT:
    t = int(t)
    t-=1
    if h == 'L':
      ans += f(n,l,t,r)
      l = t
    else:
      ans += f(n,r,t,l)
      r = t
  print(ans)

if __name__ == '__main__':
  main()

