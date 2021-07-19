n,m=map(int,input().split())
lesson=list(map(int,input().split()))

left=max(lesson)-1
right=10000*n+1

# left<right
# max(left)
while left+1<right:
    mid=(left+right)//2
    cnt=0
    sum=0
    x=0

    for i in lesson:
        if sum+i>mid:
            cnt+=1
            sum=0
            x=max(x,sum)
        sum+=i
    x=max(x,sum)
    cnt+=1

    if cnt>m: left=mid
    else: right=mid

print(left+1)