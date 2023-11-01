values = list(map(int, input().split()))
times = list(map(int, input().split()))

for i in range(values[0] - 1):
    if times[i+1] - times[i] <= values[1]:
        output = times[i+1]
        break
    else:
        output = -1

print(output)