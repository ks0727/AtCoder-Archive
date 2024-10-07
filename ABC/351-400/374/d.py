from itertools import permutations
import math
def main():
 n,s,t = map(int,input().split())
 a,b,c,d = [],[],[],[]
 for i in range(n):
  ai,bi,ci,di = map(int,input().split())
  a.append(ai)
  b.append(bi)
  c.append(ci)
  d.append(di)
  
 def dist(cx,cy,x,y,on):
   res = (cx-x)**2 + (cy-y)**2
   res = math.sqrt(res)
   if on:
     return res/t
   else:
     return res/s
 ans = 1e18
 for v in permutations(range(n)):
   for i in range(1<<n):
     now = 0
     ci,cj = 0,0 
     for j in range(n):
       if i>>j&1:
         now += dist(ci,cj,a[v[j]],b[v[j]],False)
         ci = a[v[j]]
         cj = b[v[j]]
         now += dist(ci,cj,c[v[j]],d[v[j]],True)
         ci = c[v[j]]
         cj = d[v[j]]
       else:
         now += dist(ci,cj,c[v[j]],d[v[j]],False)
         ci = c[v[j]]
         cj = d[v[j]]
         now += dist(ci,cj,a[v[j]],b[v[j]],True)
         ci = a[v[j]]
         cj = b[v[j]]
     ans = min(ans,now)
 print(ans)



  
if __name__ == '__main__':
  main()


