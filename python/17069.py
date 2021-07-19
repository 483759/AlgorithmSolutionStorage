import sys

n=int(sys.stdin.readline())

def solution(s):
    if len(s)==1: return 0
    if len(s)==2:
        if s[0]==s[1]: return 0
        return 2

    if s[0]==s[-1]:
        return solution(s[1:-1])
    
    if s[1]!=s[-1] and s[0]!=s[-2]: return 2

    m=2
    if s[1]==s[-1]:
        m=min(m,solution(s[1:]))
    if s[0]==s[-2]:
        m=min(m,solution(s[:-1]))
        
    if m==0: return 1
    return m
    
    

for _ in range(n):
    s = sys.stdin.readline().strip()
    
    print(solution(s))