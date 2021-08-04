import sys
from collections import deque

def bfs(r, c, num):
    global origin, after, n, m
    dx=[1,0,-1,0]
    dy=[0,1,0,-1]
    visit=[[False for _ in range(m)] for _ in range(n)]
    o=origin[r][c]
    
    q=deque()
    q.append([r, c])
    visit[r][c]=True
    
    while q:
        cur=q.pop()
        origin[cur[0]][cur[1]]=num
        
        for i in range(4):
            nr=cur[0]+dx[i]
            nc=cur[1]+dy[i]
            if not (nr>=0 and nr<n and nc>=0 and nc<m): continue
            if not visit[nr][nc] and origin[nr][nc]==o:
                q.append([nr, nc])
                visit[nr][nc]=True
                
def solution(n, m, origin, after):
    for i in range(n):
        for j in range(m):
            if origin[i][j]==after[i][j]: continue
            bfs(i,j,after[i][j])
            for r in range(n):
                for c in range(m):
                    if origin[r][c]!=after[r][c]: return "NO"
            return "YES"
    return "YES"

sys.stdin=open("python\input.txt","r")
input=sys.stdin.readline
n,m=map(int,input().split())

origin = []
for _ in range(n):
    origin.append(list(map(int,input().split(" "))))

after = []
for _ in range(n):
    after.append(list(map(int,input().split(" "))))  
    
print(solution(n, m, origin, after))