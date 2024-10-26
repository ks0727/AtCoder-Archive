class UnionFind:
   def __init__(self,n):
     self.n = n
     self.par = [i for i in range(n)]
     self.rank = [1]*n
     self.rb = [i for i in range(n)]

   def root(x):
     if x == self.par[x]:
       return x
     self.par[x] = root(self.par[x])
     return self.par[x]

   def merge(a,b):
     a = root(a)
     b = root(b)
     if a == b:
       return
     if self.rank[a] > self.rank[b]:
       a,b = b,a
     self.rb[a] = self.rb[b] = max(self.rb[a],self.rb[b])+1
     self.rank[b] += self.rank[a]
     self.par[a] = self.par[b]

   def same(a,b):
     return root(a) == root(b)

def main():
  q = int(input())
  n = 1<<20
  a = [-1]*n
  uf = UnionFind(n)
  qs = []
  for i in range(q):
    t,x = map(int,input().split())
    qs.append((t,x))

  for t,x in qs:
    x -= 1
    if t == 1:
      h = x%n
      if uf.rb[h] == n:
        a[uf.rb[0]] = x
        uf.merge(0,uf.rb[0])
      else:
        a[uf.rb[h]] = x
        uf.merge(h,uf.rb[h])
    elif t==2:
       print(a[x%n])
    
  
if __name__ == '__main__':
  main()


