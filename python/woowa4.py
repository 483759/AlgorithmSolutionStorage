def solution(s):
    s = s*2    
    answer = []
    
    for i in range(len(s)//2):
        if s[len(s)//2-1+i]!=s[len(s)//2+i]:
            s=s[i:i+len(s)//2]
            break
    
    i = 0
    while i<len(s):
        answer.append(1)
        while i+1<len(s) and s[i+1]==s[i]:
            answer[-1]+=1
            i+=1
    
    return answer
  
solution("aaabbaaa")