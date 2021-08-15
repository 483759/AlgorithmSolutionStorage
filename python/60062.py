from itertools import permutations

def solution(n, weak, dist):
    for p in range(1,len(dist)+1):
      
      perm = list(permutations(dist, p))
      
      for friends in perm:
        
        for i in range(len(weak)):
          cur=0
          w=0
          d=friends[0]
          
          while cur<p and w<len(weak):
            sub = (n+weak[(w+i+1)%len(weak)]-weak[(w+i)%len(weak)])%n
            
            if d>=sub:
              w+=1
              d-=sub
            else:
              cur+=1
              w+=1
              if cur<p: d=friends[cur]
          
          if w==len(weak): return p
    
    return -1
  
print(solution(12,	[1, 5, 6, 10],	[1, 2, 3, 4]))