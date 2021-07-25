n=int(input())
MOD = 1000000007
INF = 987654321
dp=[INF for _ in range(n+5)]
dp[0]=1
dp[1]=1

def fibonacci(k):
    global dp
    
    if dp[k] != INF: return dp[k]
    if k<2: 
        return k
    dp[k]=(fibonacci(k-2)+fibonacci(k-1)+1)%MOD
    return dp[k]

print(fibonacci(n)%MOD)