n,m=map(int,input().split())
money=[]
for _ in range(n):
    money.append(int(input()))

left=max(money)
right=10000*100000
ans=right

while left<=right:
    mid=(left+right)//2
    cnt=0
    l=0
    
    for i in range(n):
        if l>=money[i]:l-=money[i]
        else:
            cnt+=1
            l=mid-money[i]
        
    if cnt>m: left=mid+1
    else:
        right=mid-1
        ans=min(ans,mid)
print(left)