import sys
sys.setrecursionlimit(10**6)

n=int(input())
k=0
tet=[0]
for i in range(1,150): 
    tet.append(tet[-1]+(i*(i+1))//2)

dp=[-1 for _ in range(n+1)]
def func(x):
    global dp, tet
    if x==0: return 0
    
    if dp[x]!=-1: return dp[x]
    dp[x]=300001
    
    for i in range(150):
        if tet[i]>x: break
        dp[x]=min(dp[x],1+func(x-tet[i]))
        
    return dp[x]
    
print(func(n))
