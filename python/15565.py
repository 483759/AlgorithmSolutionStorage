n,k=map(int,input().split())
doll=list(map(int,input().split()))
left=0
right=-1
s=0
ans=n+1
while left<n and right<n:
    if s<k and right<n-1:
        right+=1
        if doll[right]==1:
            s+=1
    else:
        if s>=k and right-left+1<ans:
            ans=right-left+1
        if doll[left]==1:
            s-=1
        left+=1
if ans==n+1: print(-1)
else: print(ans)
