from math import sin,cos,pi

a,b,d = map(float,input().split())
theta = 2*pi*d/360
x = a*cos(theta)-b*sin(theta)
y = a*sin(theta)+b*cos(theta)

print(f"{x:.10f} {y:.10f}")
