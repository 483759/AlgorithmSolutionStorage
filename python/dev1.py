def solution(registered_list, new_id):
    if new_id not in registered_list:
      return new_id
  
    idx=0
    for _ in new_id:
      if new_id[idx].isdigit():
        break
      idx+=1
    s, n=new_id[:idx], new_id[idx:]
    if len(n)==0:
      n=0
    else:
      n=int(n)
      
    similar_list = []
  
    for id in registered_list:
      if id.startswith(s):
        sub_id = [id[:len(s)], id[len(s):]]
        if len(sub_id[1])==0:
          similar_list.append(0)
          continue
        elif sub_id[1].isdigit()==False:
          continue
        
        similar_list.append(int(sub_id[1]))
    
    similar_list.sort()
    
    size=len(similar_list)
    for i in range(size):
      if similar_list[i]<n: continue
      
      if i+1!=size and similar_list[i+1]!=similar_list[i]+1:
        return s+str(similar_list[i]+1)
    
    return s+str(similar_list[-1]+1)
    
  
# print(solution(["card", "ace13", "ace16", "banker", "ace17", "ace14"], "ace15"))
# print(solution(["cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"], "cow"))
print(solution(["cow"], "cow"))
# print(solution(["bird99", "bird98", "bird101", "gotoxy"], "bird98"))
# print(solution(["apple1", "orange", "banana3"], "apple"))