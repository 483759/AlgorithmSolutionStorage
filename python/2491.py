n=int(input())
arr=list(map(int,input().split()))

ans=1
dp=[[1 for _ in range(n+1)] for _ in range(2)]

for i in range(1, n):
    if arr[i-1]<=arr[i]:
        dp[0][i]=dp[0][i-1]+1
    ans=max(ans,dp[0][i])

for i in range(n-1, 0, -1):
    if arr[i-1]>=arr[i]:
        dp[1][i-1]=dp[1][i]+1
    ans=max(ans,dp[1][i-1])    

print(ans)

        