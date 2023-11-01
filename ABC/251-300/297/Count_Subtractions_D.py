"""
以下は自分の回答
A,B = map(int, input().split())
i = 0
while A != B:
    if A > B:
        A = A - B
    else:
        B = B - A
    i += 1
    

print(i)
"""
"""
うえの自分の回答だと、A=10^8 B=1 などのときに実行制限時間をオーバーしてしまいます。よって、何かしらの工夫が必要となる。
そこで、以下の手順で考える
1. A > Bになるようにswap
2. B = 0になるまで以下を繰り返す
　- 答えに A / Bを足して、 Aを A mod Bで置き換える
　- A, Bをswapする
3. 最後に答えから1をひく
"""
#以下は公式の回答
A, B = map(int, input().split())
ans = 0
if A < B:
    A,B = B,A
while B > 0:
    ans += int(A / B)
    A %= B
    A,B = B,A
ans -= 1
print(ans)
