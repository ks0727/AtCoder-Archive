def main():
  x = input()
  ans,r = x.split('.')
  ans = int(ans)
  r = int(r)
  if r/100 >= 5:
    ans+=1
  print(ans)  
if __name__ == '__main__':
  main()


