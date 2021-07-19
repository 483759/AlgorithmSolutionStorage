import sys

sys.stdin=open('input.txt','r')
n=int(sys.stdin.readline())
graph=[0]
time=[0]
ans=[0]
In=[0]
for _ in range(n):
    li=list(map(int,sys.stdin.readline().split()))[:-1]
    time.append(li[0])
    graph.append(li[1:])
    In.append(len(graph[-1]))
    
print(In)
print(time)
print(graph)