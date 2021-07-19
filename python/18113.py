import sys

n,k,m=map(int,sys.stdin.readline().strip().split())
arr=[]
for _ in range(n):
  arr.append(int(sys.stdin.readline()))
arr.sort(reverse=True)

left=0
right=arr[0]+1
while left+1<right:
  mid=(left+right)//2

  cnt=0
  for a in arr:
    if a<=k:break
    elif a<2*k: a-=k
    else: a-=2*k
    if a>=mid: cnt+=a//mid
  
  if cnt>=m:
    left=mid
  else:
    right=mid
if left==0: print(-1)
else: print(left)