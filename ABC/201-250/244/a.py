import random

n = random.randint(1,1000);
print(n)
a = []
for i in range(1,2*n+2):
  a.append(int(i))

a = set(a)
t = 0
while len(a) > 0:
  if t % 2 == 0:
    x = input()
    print(type(x))
    a.discard(x)
  else:
    x = next(iter(a))
    print(x)
    a.discard(x)
    
  t+=1


