def solution(rows, cols):
    answer = [[0 for _ in range(cols)] for _ in range(rows)]
    r, c = 0, 0
    answer[0][0] = 1
    preNum = 1
    count = rows*cols - 1
    
    while count!=0:      
      if preNum%2:
        c = (c + 1)%cols
      else:
        r = (r + 1)%rows
        
      if answer[r][c]==0:
        count-=1
      elif rows==cols:
        break
        
      answer[r][c] = preNum+1
      preNum+=1
        
    return answer
  
# print(solution(3, 4))
# print(solution(4, 3))
# print(solution(3, 3))
print(solution(1000, 1000))