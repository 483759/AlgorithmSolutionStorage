tc=int(input())
for _ in range(tc):
  n=int(input())
  arr=list(map(int,input().split()))

  dp=[0 for _ in range(n)]
  dp[0]=arr[0]
  ans=dp[0]
  for i in range(1,n):
    if dp[i-1]+arr[i]>arr[i]:
      dp[i]=dp[i-1]+arr[i]
    else: dp[i]=arr[i]
    if dp[i]>ans:ans=dp[i]
  print(ans)