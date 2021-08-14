import sys
from collections import deque

sys.stdin=open('python/input.txt','r')
input=sys.stdin.readline

n,t,w=map(int,input().split())
customer = deque()

for _ in range(n):
  customer.append(list(map(int,input().split())))

m=int(input())
li = [list(map(int,input().split())) for _ in range(m)]
li.sort(key=lambda x:x[2])
enter = deque()

for i in range(m):
  enter.append(li[i])

left=t
for time in range(w):
  if len(enter)!=0 and enter[0][2]==time:
    customer.append([enter[0][0],enter[0][1]])
    enter.popleft()
  
  if customer[0][1]==0:
    customer.popleft()
    left=t
  elif left!=0:
    customer[0][1]-=1
    left-=1
  else:
    customer.append(customer[0])
    customer.popleft()
    customer[0][1]-=1
    left=t-1
  print(customer[0][0])
  