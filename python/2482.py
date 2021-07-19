N=int(input())
K=int(input())
mod=1000000003

dp=[[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(N+1):
  dp[i][0]=1
  dp[i][1]=i

for i in range(2,N+1):
  for j in range(2,K+1):
    dp[i][j]=(dp[i-2][j-1]+dp[i-1][j])%mod

print((dp[N-1][K]+dp[N-3][K-1])%mod)