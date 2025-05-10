import sys
sys.setrecursionlimit(10**6)

def main():
  n,m = map(int,input().split())
  c = list(map(int,input().split()))
  k = []
  a = [] 
  zoo_to_animal = [[] for _ in range(n)]
  for i in range(m):
    ka = list(map(int,input().split()))
    ki = ka[0]
    ai = ka[1:]
    k.append(ki)
    ai = [x-1 for x in ai]
    a.append(ai)
    for x in ai:
      zoo_to_animal[x].append(i)
  ans = [1001001001]
  def f(d,now,cnt):
    if d == n:
      for i in range(m):
        if cnt[i] < 2:
          return
      ans[0] = min(ans[0],now)
      return
    for i in range(3):
      cnt2 = cnt.copy()
      now2 = now + c[d] * i
      for x in zoo_to_animal[d]:
        cnt2[x] += i
      f(d+1,now2,cnt2)
      
  f(0,0,[0]*m)
  print(ans[0])


if __name__ == '__main__':
  main()


