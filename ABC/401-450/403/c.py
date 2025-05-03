def main():
  n,m,q = map(int,input().split())
  done = [False]*n
  auth = [set() for _ in range(n)]
  for _ in range(q):
    txy = list(map(int,input().split()))
    t = txy[0]
    if t == 1:
      x,y = txy[1:]
      x-=1; y -= 1;
      auth[x].add(y)
    elif t == 2:
      x = txy[1]
      x -= 1
      done[x] = True
    else:
      x,y = txy[1:]
      x -=1; y -=1;
      if done[x]:
        print("Yes")
      elif y in auth[x]:
        print("Yes")
      else:
        print("No")

if __name__ == '__main__':
  main()


