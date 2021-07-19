n=int(input())
INF=987654321

arr=[INF for _ in range (100001)]
arr[2]=arr[5]=1
arr[4]=2
for i in range(6,n+1):
    if arr[i-2]==INF and arr[i-5]==INF: continue
    arr[i]=min(arr[i-2],arr[i-5])+1
    
if arr[n]==INF:print(-1)
else: print(arr[n])