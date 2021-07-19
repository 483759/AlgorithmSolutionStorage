n,k=map(int,input().split())

arr=[]
for _ in range(n):
    arr.append(int(input()))
arr.sort()

left=0
right=1000000001

while left+1<right:
    mid=(left+right)//2

    level = k
    for x in arr:
        if x<mid and level>=0:
            level-=mid-x
        else:break
    
    if level>=0:
        left=mid
    else:right=mid
        

print(left)