import sys
from collections import deque

sys.stdin=open("python/input.txt","r")
input=sys.stdin.readline

n=int(input())
m=int(input())
p=list(map(int,input().split()))
safety=[21 for _ in range(n+1)]
dq=deque()

for i in p: 
    safety[i]=0
    dq.append(i)
    
ans=0

while len(dq)!=0:
    cur=dq.popleft()
    
    for i in range(20):
        x = (1<<i) ^ cur
        if x<=n and safety[cur]+1<safety[x]:
            safety[x]=safety[cur]+1
            ans=max(safety[x],ans)
            dq.append(x)
print(ans)