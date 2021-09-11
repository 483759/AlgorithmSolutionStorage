def solution(board, skill):
    answer = 0
    
    for s in skill:
      if s[0]==1:
        for i in range(s[1], s[3]+1):
          for j in range(s[2], s[4]+1):
            board[i][j]-=s[5]
            
      if s[0]==2:
        for i in range(s[1], s[3]+1):
          for j in range(s[2], s[4]+1):
            board[i][j]+=s[5]
    
    for i in range(len(board)):
      for j in range(len(board[0])):
        if board[i][j]>=1:
          answer+=1
        
    return answer
  
print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]],[[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))