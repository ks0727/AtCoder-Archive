import sys
n = int(input())
s = input()

d = {'R':(1,0),'L':(-1,0),'U':(0,1),'D':(0,-1)}
st = set()
st.add((0,0))
prev = (0,0)
for idx,c in enumerate(s):
    i = prev[0]
    j = prev[1]
    if c == 'R':
        i+=1
    elif c == 'L':
        i-=1
    elif c == 'U':
        j+=1
    else:
        j-=1
    if (i,j) in st:
        print("Yes")
        sys.exit(0)
    prev = (i,j)
    st.add(prev)

print("No")