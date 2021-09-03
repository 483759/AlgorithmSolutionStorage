import sys

sys.stdin=open('python/input.txt','r')

t=int(input())

def toBinary(s):
  ans=[]
  while s != 0:
    if s%2==0:
      ans.insert(0,'V')
    else:
      ans.insert(0,"딸기")
    s//=2
  
  while len(ans) != 4:
    ans.insert(0,'V')
  return ''.join(ans)

for _ in range(t):
  n=int(input())
  
  n=((n-1)%28+1)
  if n<=15:
    print(toBinary(n))
  else:
    print(toBinary(30-n))
  