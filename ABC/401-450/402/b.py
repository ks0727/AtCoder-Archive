def main():
  q = int(input())
  offset = 0
  arr  = []
  for _ in range(q):
    qi = list(map(int,input().split()))
    if len(qi) == 2:
      x = qi[1]
      arr.append(x)
    else:
      print(arr[offset])
      offset += 1


if __name__ == '__main__':
  main()


