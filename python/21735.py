n,m=map(int,input().split())
a=list(map(int,input().split()))

def func(cur, dep, size):
  global a, m
  if cur>=len(a) or dep>=m: 
    return size
  
  ret = size
  if cur+1<len(a):
    ret = max(ret, func(cur+1, dep+1, size+a[cur+1]))
  if cur+2<len(a):
    ret = max(ret, func(cur+2, dep+1, size//2+a[cur+2]))
  
  return ret

a.insert(0, 0)
print(func(0, 0, 1))