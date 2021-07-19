import sys

sys.stdin=open('input.txt','r')
n=int(sys.stdin.readline().strip())
d=[[]]
for i in range(1,n+1):
    d.append(list(map(int,sys.stdin.readline().split())))
    d[-1].remove(d[-1][0])

ans=[10 for _ in range(n+1)]
dp=[[10 for _ in range(10)]for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(len(d[i])):
        for k in range(len(d[i-1])):
            if d[i-1][k]==d[i][j]:continue
            dp[i][j]=d[i-1][k]

def path(cur,dep):
    global dp, d
    if dp[dep][cur]!=10:
        path(dp[dep][cur],dep-1)
    print(cur)

for i in range(len(dp[-1])):
    if dp[-1][i] != 10:
        path(dp[-1][i],n)
        print(d[-1][i])
        exit(0)
print(-1)