def solution(jobs):
    time=jobs[0][0]
    task=[jobs[0][2],jobs[0][1]]
    answer = [task[0]]
    cur=1
    fin=0
    cnt=len(jobs)
    ready=[[0, 0] for _ in range(101)]
    
    while fin!=cnt:
        if answer[-1]!=task[0]:
            answer.append(task[0])
        
        if cur!=cnt and jobs[cur][0]==time:
            ready[jobs[cur][2]][0]+=jobs[cur][3]
            ready[jobs[cur][2]][1]+=jobs[cur][1]
            cur+=1
        
        if ready[task[0]][1]!=0:
            task[1]+=ready[task[0]][1]
            ready[task[0]]=[0, 0]
            
        if task[1]<=0:
            next=0
            priority_sum=0
            
            for i in range(100):
                if ready[i][0]>priority_sum:
                    next=i
                    priority_sum=ready[i][0]
            
            if next==0:
                if cur!=cnt:
                    time=jobs[cur][0]
                    continue
                else:
                    break
            
            task=[next, ready[next][1]]
            ready[next]=[0, 0]
            fin+=1
        
        task[1]-=1
        time+=1
    
    return answer

print(solution([[1, 5, 2, 3], [2, 2, 3, 2], [3, 1, 3, 3], [5, 2, 1, 5], [7, 1, 1, 1], [9, 1, 1, 1], [10, 2, 2, 9]]))
# print(solution([[0, 2, 3, 1], [5, 3, 3, 1], [10, 2, 4, 1]]))