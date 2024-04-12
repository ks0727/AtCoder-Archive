n,m = map(int,input().split())
g = [[] for _ in range(n*2)]

class UF:
    def __init__(self,n):
        self._n = n
        self.parent = [-1]*n

    def leader(self,a):
        parent = self.parent[a]
        while parent >= 0:
            if self.parent[parent] < 0:
                return parent
            self.parent[a] , a, parent = (
                self.parent[parent],
                self.parent[parent],
                self.parent[self.parent[parent]]
            )
        return a
    
    def merge(self,a,b):
        leaders = [str(x) for x in self.parent]
        s = " ".join(leaders)
        print(s)
        x = self.leader(a)
        y = self.leader(b)
        if x == y:
            return x
        if -self.parent[x] < -self.parent[y]:
            x,y = y,x
        self.parent[x] += self.parent[y] #xのサイズはyのサイズを足したものになる
        self.parent[y] = x #yの親をxに変更する
        return x
    
    def same(self,a,b):
        return self.parent[a] == self.parent[b]
    
connected = [False for _ in range(n*2)]
uf = UF(n)
for i in range(m):
    a,b,c,d = input().split()
    a = int(a)-1
    c = int(c)-1
    uf.merge(a,c)
    if b == 'B':
        a += n
    if d == 'B':
        c += n
    connected[a] = True
    connected[c] = True
loop = [True for _ in range(n)]

groups = set()
for i in range(n):
    groups.add(uf.leader(i))
    if not connected[i] or not connected[i+n]:
        loop[uf.leader(i)] = False


total = len(groups)
not_loop = 0
for i in range(n):
    if i in groups and not loop[i]:
        not_loop += 1

#print(total-not_loop,not_loop)
