def main():
  s = input()
  cnt = 0
  for i in range(len(s)-1):
    if s[i] == s[i+1]:
      cnt+=1

  if s[0] == 'o' and (len(s)+int(cnt))%2 == 0:
    cnt += 2
  elif s[0] == 'o' and (len(s) + int(cnt))%2 == 1:
    cnt += 1
  elif s[0] == 'i' and (len(s)+int(cnt))%2 == 1:
    cnt += 1
  print(cnt)
if __name__ == '__main__':
  main()


