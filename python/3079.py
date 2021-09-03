import sys

sys.stdin=open('python/input.txt','r')
input=sys.stdin.readline

n,m=map(int,input().split())
t=[]

for _ in range(n):
  t.append(int(input()))

left=0
right=10**19
while left+1<right:
  mid=(left+right)//2
  cnt=0

  for time in t:
    cnt+=mid//time

  if cnt>=m:
    right=mid
  else:
    left=mid
print(right)