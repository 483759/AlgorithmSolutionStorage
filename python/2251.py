import sys

sys.stdin=open("python/input.txt","r")
arr[0]=list(map(int,sys.stdin.readline().split()))

v=[0,0,arr[2]]
ans=[]
visit=[[[False for _ in range (arr[2]+1)] for _ in range(arr[1]+1)] for _ in range(arr[0]+1)]

def func(a, b, c):
    global v
    if visit[v[0]][v[1]][v[2]]: return
    visit[v[0]][v[1]][v[2]]=True
    for i in range(3):
        if v[i]==0: continue
        for j in range(3):