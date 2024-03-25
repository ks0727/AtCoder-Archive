import bisect

n,t = map(int,input().split())
a = list(map(int,input().split()))

s = [0 for _ in range(n+1)]
for i in range(n):
    s[i+1] = s[i] + a[i]
rest = t%s[-1] #残り時間
song = bisect.bisect_left(s,rest)
sec = rest - s[song-1]
print(song,sec)


