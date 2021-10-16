import pprint

def safe(r, c):
  return r>=0 and r<6 and c>=0 and c<6

def pile(board, col, num):
    row = 0
    while row<6:
      if board[row][col]!=0:
        break
      row+=1
      
    board[row-1][col]=num

def pop(board):
  visit=[[False for _ in range(6)] for _ in range(6)]
  dr, dc = [1, 0, -1, 0], [0, 1, 0, -1]
  flag = False
  
  for i in range(6):
    for j in range(6):
      if visit[i][j] or board[i][j]==0: continue
      
      s=[[i, j]]
      same=[[i,j]]
      visit[i][j]=True
      
      while len(s)!=0:
        r, c=s[-1]
        s.pop()
        visit[r][c]=True
        
        for k in range(4):
          nr, nc=r+dr[k],c+dc[k]
          
          if safe(nr, nc)==False or visit[nr][nc] or board[nr][nc]!=board[i][j]: continue
          s.append([nr,nc])
          same.append([nr,nc])
      
      if len(same)>=3:
        flag = True
        for m in same:
          board[m[0]][m[1]]=0
      
  return flag

def gravity(board):
  for j in range(6):
    q=[]
    
    for i in range(5, -1, -1):
      if board[i][j]!=0:
        q.append(board[i][j])
      board[i][j]=0
    
    for i in range(5, -1, -1):
      if len(q)==0:
        break
      board[i][j]=q[0]
      q.pop(0)

def solution(macaron):
  answer = []
  board = [[0 for _ in range(6)] for _ in range(6)]
  
  for m in macaron:    
    pile(board, m[0]-1, m[1])
    
    while True:
      flag = pop(board)
      if flag==False: break
      gravity(board)
      
  for i in range(6):
    answer.append('')
    for j in range(6):
      answer[i]+=str(board[i][j])
  
  return answer

print(solution([[1,1],[2,1],[1,2],[3,3],[6,4],[3,1],[3,3],[3,3],[3,4],[2,1]]))