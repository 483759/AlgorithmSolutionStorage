n,k,b=map(int,input().split())
s=[0 for _ in range(n+1)]

for _ in range(b):
    s[int(input())-1]=1

f=0
left=0
right=0
for i in range(k):
    if s[i]==1:
        f+=1
    right+=1
right-=1

ans=f
for i in range(k,n):
    right+=1
    if s[right]==1:
        f+=1

    if s[left]==1:
        f-=1
    left+=1
    if f < ans:ans=f
print(ans)