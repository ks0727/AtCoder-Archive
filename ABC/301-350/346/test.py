n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
l = int(input())
c = list(map(int,input().split()))
q = int(input())
X = list(map(int,input().split()))

st = set()
for x in a:
    for y in b:
        for z in c:
            st.add(x+y+z)

for xi in X:
    if xi in st:
        print("Yes")
    else:
        print("No")
