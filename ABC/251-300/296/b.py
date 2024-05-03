import sys
s = [input() for _ in range(8)]
abc = "abcdefgh"
num = "87654321"
for i in range(8):
  for j in  range(8):
    if(s[i][j] == '*'):
      print(abc[j]+num[i])
      sys.exit(0)




