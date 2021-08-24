import sys

sys.setrecursionlimit(10**6)
sys.stdin=open('python/input.txt','r')
input=sys.stdin.readline

def dp(s, f):
  global origin, r, cache

  if s>=f: return 0
  if cache[s][f]!=-1: return cache[s][f]
  sub=origin[s:f]

  cache[s][f]=0
  for i in range(s, f):
    cache[s][f]=max(cache[s][f], dp(s, i) + dp(i + 1, f) + 1)

  for recode in r:
    key=recode[0]
    value=recode[1]

    index=sub.find(key)
    if index==-1: continue
    index+=s
    cache[s][f]=max(cache[s][f], dp(s, index) + dp(index+len(key), f) + value)

  return cache[s][f]

def func(index):
  global origin

  if index>=len(origin): return 0
  if cache[index]!=-1: return cache[index]

  # cache[index]=0
  cache[index]=func(index+1)+1

  for recode in r:
    key=recode[0]
    value=recode[1]

    # index=origin[index:].find(key)
    # if index==-1: continue
    if origin[index:index+len(key)]==key:
      cache[index]=max(cache[index], func(index+len(key))+value)

  return cache[index]

origin=input()[:-1]
m=int(input())
# cache=[[-1 for _ in range(len(origin)+1)] for _ in range(len(origin)+1)]
cache=[-1 for _ in range(len(origin)+1)]
r=[]

for _ in range(m):
  r.append(list(map(str,input().split())))
  r[-1][1]=int(r[-1][1])

# print(dp(0,len(origin)))
print(func(0))
