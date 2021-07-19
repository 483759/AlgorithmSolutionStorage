n=int(input())
k=int(input())

left=1
right=k+1
ans=1
while left+1<right:
  mid=(left+right)//2
  cnt=0
  
  for i in range(1,n+1):cnt+=min(mid//i,n)
  if cnt<k: left=mid
  else: 
    right=mid
print(left)
