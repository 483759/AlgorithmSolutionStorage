import sys
sys.setrecursionlimit(10**6)

x=int(input())
dp=[987654321 for _ in range(x+1)]
pre=[-1 for _ in range(x+1)]

def func(n):
    global dp
    if n==1: return 0
    if dp[n]!=987654321: return dp[n]
    
    if n%3==0 and func(int(n/3))+1<dp[n]:
        dp[n]=func(int(n/3))+1
        pre[n]=int(n/3)
        
    if n%2==0 and func(int(n/2))+1<dp[n]:
        dp[n]=func(int(n/2))+1
        pre[n]=int(n/2)
    
    if  func(n-1)+1<dp[n]:
        dp[n]=func(n-1)+1
        pre[n]=n-1
        
    return dp[n]

print(func(x))
while pre[x]!=-1:
    print(x,end=' ')
    x=pre[x]
print(x) 