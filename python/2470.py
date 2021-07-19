n=int(input())
w=sorted(map(int,input().split()))
#print(w)
left=0
right=n-1
ans=[left,right]
m=abs(w[left]+w[right])
while(left<right):
    #print(str(left)+" "+str(right))
    if abs(w[left]+w[right])<m:
        m=abs(w[left]+w[right])
        ans=[w[left],w[right]]
    if abs(w[left+1]+w[right])<abs(w[left]+w[right-1]):
        left+=1
    else:
        right-=1
print(str(ans[0])+" "+str(ans[1]))