n,m=map(int,input().split())

s=[input() for _ in range(n)]

b=True
for i in range(n):
    t=input()
    for j in range(m):
        if t[2*j]!=s[i][j] or t[2*j+1]!=s[i][j]: b=False
if b: print("Eyfa")
else: print("Not Eyfa")