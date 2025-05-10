def main():
  s = input()
  cnt = [0]*26
  for i in range(len(s)):
    cnt[ord(s[i])-ord('a')] += 1
  
  for i in range(26):
    if cnt[i] == 0:
      print(chr(i+ord('a')))
      exit()

if __name__ == '__main__':
  main()


