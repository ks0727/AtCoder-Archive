class UnionFind:
  def __init__(self,n):
    self.n = n
    self.par = [i for i in range(n)]
    self.rank = [1]*n

  def root(x):
    if x == self.par[x]:
      return x
    return self.par[x] = root(par[x])
  
  def merge(a,b):
    a = root(a)
    b = root(b)
    if a == b:
      return
    if self.rank[a] > self.rank[b]:
      a,b = b,a
    self.rank[b] += self.rank[a]
    self.par[a] = self.par[b]
  
  def same(a,b):
    return root(a) == root(b)

def main():
  n,x = map(int,input().split())
  uf = UnionFind(n)

if __name__ == '__main__':
  main()


