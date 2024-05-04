n,x,y = map(int,input().split())
red = [0]*12
blue = [0]*12
red[0] = 1

for i in range(n-1):
    blue[i] = red[i]*x
    red[i+1] = red[i] + blue[i]
    blue[i+1] = y*blue[i]
print(red)
print(blue)
print(blue[n-2])