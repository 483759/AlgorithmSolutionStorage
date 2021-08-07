import sys

input=sys.stdin.readline
n,k=map(int,input().split())
l=list(map(int,input().split()))
cache=[[-1 for _ in range(n+1)] for _ in range(2)]

def dp(b, k):
    global cache, l
    
    if(k==n): return 1
    if cache[b][k] != -1: return cache[b][k]
    
    if b==0:
        cache[b][k]=max(dp(0,k+1), dp(1,k+1))+1
    else: 
        cache[b][k]=dp(0,k+1)+1
    
    return cache[b][k]

m=0
for i in range(n+1):
    m=max(m,cache[0][i],cache[1][i])
print(m)
    
