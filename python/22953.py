import sys

sys.stdin=open('python/in                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               put.txt','r')
input=sys.stdin.readline

n,k,c=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a)-len(a)

def comb(idx, dep):
  global a, k, s

  if dep==c or dep>=s:
    left=0  
    right=10**13
    while left+1<right:
      mid=(left+right)//2
      cnt=0

      for x in a:
        cnt+=mid//x

      if cnt>=k: right=mid
      else: left=mid

    return right

  ans=10**13
  for i in range(idx, len(a)):
    if a[i]==1:continue

    a[i]-=1
    ans=min(ans,comb(i, dep+1))
    a[i]+=1

  return ans

print(comb(0, 0))