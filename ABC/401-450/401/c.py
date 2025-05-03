def main():
  n,k = map(int,input().split())
  a = [1]*(n+1)
  now = k
  MOD = 1000000000
  if k > n:
    print(1)
    exit(0)
  a[k] = now
  for i in range(n-k):
    now -= a[i]
    now += a[i+k]
    now = now%MOD
    a[i+k+1] = now 
  print(a[n])
if __name__ == '__main__':
  main()


