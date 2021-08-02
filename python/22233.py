import sys

n,m=map(int,sys.stdin.readline().split())
s=set()
for _ in range(n):
    s.add(sys.stdin.readline().strip())
    
for _ in range(m):
    keys=list(sys.stdin.readline().strip().split(','))
    
    for key in keys:
        if key in s: s.remove(key)
    
    print(len(s))