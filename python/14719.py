h,w=map(int,input().split())
block=list(map(int,input().split()))
board=[[0 for _ in range(w)] for _ in range(h)]

for j in range(len(block)):
    for i in range(0,block[j]): board[h-1-i][j]=1

ans=0
for i in range(h):
    b=False
    cnt=0
    for j in range(w):
        if board[i][j]==1:
            b=True
            ans+=cnt
            cnt=0
        elif b: cnt+=1
print(ans)