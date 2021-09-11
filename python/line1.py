def solution(student, k):
    answer = 0
    student.insert(0, 0)
    prefix_sum = [s for s in student]
    
    for i in range(1, len(prefix_sum)):
      prefix_sum[i]+=prefix_sum[i-1]
    
    for i in range(1, len(student)):
      for j in range(i, len(student)):
        sum = prefix_sum[j] - prefix_sum[i - 1]
        if sum==k: 
          answer+=1
        
    return answer
  
print(solution([0,1,0,0], 1))