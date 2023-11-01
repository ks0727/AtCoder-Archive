S = input()
b_pos = []
r_pos = []

for i in range(8):
    if S[i] == 'B':
        b_pos.append(i)
    elif S[i] == 'K':
        k_pos = i
    elif S[i] == 'R':
        r_pos.append(i)

if (b_pos[0] + b_pos[1]) % 2 == 1:
    if k_pos > r_pos[0] and k_pos < r_pos[1]:
        print("Yes")
    else:
        print("No")
else:
    print("No")

