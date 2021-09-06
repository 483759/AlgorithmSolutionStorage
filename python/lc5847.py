def safe(r, c, n, m):
  return r>=0 and r<n and c>=0 and c<m

def findFarmland(land):
  answer=[]
  n,m=len(land), len(land[0])
  dx,dy=[1,0,-1,0],[0,1,0,-1]
  
  for r in range(n):
    for c in range(m):
      i,j=r,c
      if land[i][j]!=1:continue
      
      if (safe(i-1, j, n, m) and land[i-1][j]==1) or (safe(i, j-1, n, m) and land[i][j-1]==1): continue
      
      answer.append([i,j,i,j])
      
      while safe(i+1, j, n, m) and land[i+1][j]==1:
        i+=1
        answer[-1][2]+=1
      
      while safe(i, j+1, n, m) and land[i][j+1]==1:
        j+=1
        answer[-1][3]+=1
      
  answer.pop()
  return answer

print(findFarmland([[1,1,0,0,0,1],[1,1,0,0,0,0]]))