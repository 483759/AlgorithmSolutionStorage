n,k=map(int,input().split())

ans=0
while bin(n).count('1')>k:
    p=2**(bin(n)[::-1].index('1'))
    ans+=p
    n+=p
print(ans)