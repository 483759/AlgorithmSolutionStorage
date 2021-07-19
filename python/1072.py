x,y=map(int,input().split())

origin_z=int((y*100)/x)

if origin_z>=99:
    print(-1)
else:
    left=0
    right=x+1
    ans=right
    while left<=right:
        mid=int((left+right)/2)

        new_z = int(((y+mid)/(x+mid))*100)
        if new_z != origin_z:
            right=mid-1
            ans=min(ans,mid)
        else:
            left=mid+1
    print(ans)
