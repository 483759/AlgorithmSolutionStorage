def edit_distance(a, b):
    edit = [[42 for _ in range(len(b))]for _ in range(len(a))]
    for i in range(len(edit)):
      for j in range(len(edit[0])):
        if i==0: edit[i][j]=j
        elif j==0: edit[i][j]=i
        else: 
          if a[i]!=b[j]:
            edit[i][j]=min(edit[i-1][j], edit[i][j-1])+1
          else: edit[i][j]=edit[i-1][j-1]
    return edit[len(a)-1][len(b)-1]

def solution(nicks, emails):
    answer = len(nicks)
    nicks_slr=[[101 for _ in range(len(nicks))]for _ in range(len(nicks))]
    
    for i in range(len(nicks)):
      for j in range(i+1, len(nicks)):
        a=' '+nicks[i]
        b=' '+nicks[j]
        
        nicks_slr[i][j]=edit_distance(a, b)
        
    for i in range(len(emails)):
      for j in range(i+1, len(emails)):
        a=emails[i].split('@')
        b=emails[j].split('@')
        
        if nicks_slr[i][j]<=2:
          if a[0]==b[0]:
            answer-=1
          else:
            similarity = edit_distance(a[0],b[0])
            if similarity==1 and a[1]==b[1]:
              answer-=1
              
    return answer