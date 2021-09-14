def solution(enter, leave):
    answer = [set() for _ in range(len(enter)+1)]
    room = []
    
    l, r=0, 0
    
    while l<len(enter) and r<len(leave):
      if leave[r] not in room:
        answer[enter[l]]=set(room[:])
        room.append(enter[l])
        l+=1
      else:
        room.remove(leave[r])
        r+=1
    
    for i in range(len(answer)):
      for j in answer[i]:
        answer[j].add(i)
    
    return [len(answer[k]) for k in range(1, len(answer))]
  
#print(solution([1,3,2],[1,2,3]))
print(solution([1,4,2,3],[2,1,3,4]))