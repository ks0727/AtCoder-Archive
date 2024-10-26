def main():
  n,w = map(int,input().split())
  pizzas = []
  for i in range(n):
    ai,bi = map(int,input().split())
    pizzas.append((ai,bi))

  pizzas = sorted(pizzas,reverse=True)
  ans = 0
  for a,b in pizzas:
     use = min(b,w)
     ans += a*use
     w -= use
     if w <= 0:
       break

  print(ans)

    
if __name__ == '__main__':
  main()


