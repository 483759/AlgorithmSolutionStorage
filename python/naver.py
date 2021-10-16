import pprint

def safe(cr, cc, r, c, width):
  return cr>=r and cr<r+width and cc>=c and cc<c+width

def divideAndConquer(r, c, num, width, idx, arr, board):
  L=arr[idx]
  W=width//L
  
  if idx<0:
    board[r][c]=num
    return board[r][c]+1
  
  sr, sc=r, c
  dc, dr=[1, 0, -1, 0], [0, 1, 0, -1]
  dir=0
  
  for _ in range(L*L):
    num = divideAndConquer(r, c, num, W, idx-1, arr, board)
    
    nr, nc = r+dr[dir]*W, c+dc[dir]*W
    if safe(nr, nc, sr, sc, width) == False or board[nr][nc]!=0:
      dir=(dir+1)%4
      nr, nc = r+dr[dir]*W, c+dc[dir]*W
    r, c=nr, nc
    
  return num

def solution(arr):
  W=1
  for a in arr: W*=a  
  board=[[0 for _ in range(W)] for _ in range(W)]
  
  divideAndConquer(0, 0, 1, W, len(arr)-1, arr, board)
  
  return board

pprint.pprint(solution([3, 2]))
pprint.pprint(solution([2, 2, 2]))