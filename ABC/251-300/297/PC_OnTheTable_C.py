"""以下自分でかいたコード

values = list(map(int, input().split()))
H = values[0]
W = values[1]
S = []
for i in range(H):
    S.append(input())

for i in range(H):
    for j in range(W - 1):
        if S[i][j] == 'T' and S[i][j+1] == 'T':
            print(S[i][j].replace('T','P'))
            print(S[i][j+1].replace('T','C'))
            
for i in range(H):
    print(S[i])

"""

#以下は公式の回答
H,W = map(int, input().split())
inputs = []
for _ in  range(H):
    inputs.append(input())

for i in range(len(inputs)):
    print(inputs[i].replace('TT','PC'))