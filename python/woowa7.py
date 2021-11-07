def safe(x, y, n):
  return x<(n*2-1) and y<n

def rotateClockwise(grid):
  dx = [0, 1]
  dy = [1, 0]
  answer = []
  
  for j in range(len(grid[0])//2+1):
    i = 0
    while i<len(grid) and grid[i][j]=='-':
      i+=1
    
    t = 0
    answer.append("")
    while(safe(j, i, len(grid))):
      answer[-1] = grid[i][j] + answer[-1]
      i += dy[t]
      j += dx[t]
      t = (t+1)%2
      
  return answer

def rotateCounterclockwise(grid):
  dx = [0, -1]
  dy = [1, 0]
  answer = []
  
  for j in range(len(grid[0])-1, len(grid[0])//2-1, -1):
    i = 0
    while i<len(grid) and grid[i][j]=='-':
      i+=1
    
    t = 0
    answer.append("")
    while(safe(j, i, len(grid))):
      answer[-1] = answer[-1] + grid[i][j]
      i += dy[t]
      j += dx[t]
      t = (t+1)%2
      
  return answer

def solution(grid, clockwise):
    answer = []
    for i in range(len(grid)):
      grid[i] = '-'*(len(grid)-i-1)+grid[i]+'-'*(len(grid)-i-1)
    
    if clockwise:
      return rotateClockwise(grid)
    else: 
      return rotateCounterclockwise(grid)
  
print(solution(["1","234","56789"], True))
print(solution(["A","MAN","DRINK","WATER11"], False))