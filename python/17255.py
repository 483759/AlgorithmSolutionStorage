import sys

n=int(sys.stdin.readline())
dp={}

def solution(cur):
    global dp
    if dp.get(cur) is not None: return dp[cur]
    if len(cur)==1:
        dp[cur]=1
        return dp[cur]
    
    a=cur[:-1]
    b=cur[1:]
    if a!=b:
        dp[cur]=solution(a)+solution(b)
    else: dp[cur]=solution(a)
    return dp[cur]

print(solution(str(n)))