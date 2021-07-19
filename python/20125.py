n=int(input())
board=[]

for _ in range(n):
  board.append(input())

h=[0,0]
ans=[0,0,0,0,0]
b=True
for i in range(n):
  for j in range(n):
    if board[i][j]=='*' and b:
      h=[i+1,j]
      b=False

dx=[-1,1,0]
dy=[0,0,1]
end=[0,0]

def safe(p):
  return p[0]>=0 and p[0]<n and p[1]>=0 and p[1]<n

for i in range(3):
  cur=[h[0],h[1]] 
  while safe(cur) and board[cur[0]][cur[1]]=='*':
    ans[i]+=1
    cur[0]+=dy[i]
    cur[1]+=dx[i]
  ans[i]-=1
  if i==2:
    end=[cur[0],cur[1]]

cur=[end[0],end[1]-1]
while safe(cur) and board[cur[0]][cur[1]]=='*':
  ans[3]+=1
  cur[0]+=1
    
cur=[end[0],end[1]+1]
while safe(cur) and board[cur[0]][cur[1]]=='*':
  ans[4]+=1
  cur[0]+=1

h[0]+=1
h[1]+=1
print(*h)
print(*ans)
