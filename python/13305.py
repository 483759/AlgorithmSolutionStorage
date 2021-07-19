n=int(input())
road=list(map(int,input().split()))
price=list(map(int,input().split()))

ans=0
i=0
while i<n-1:
  next=i+1
  len=road[i]
  while next<n-1 and price[next]>price[i]:
    len+=road[next]
    next+=1
  ans+=price[i]*len
  i=next
print(ans)
  
