n,m=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
ans=[]

a=0
b=0
while a!=len(A) or b!=len(B):
    if a==len(A): 
        ans.append(B[b])
        b+=1
    elif b==len(B):
        ans.append(A[a])
        a+=1
    else:
        if A[a]<B[b]:
            ans.append(A[a])
            a+=1
        else:
            ans.append(B[b])
            b+=1

print(*ans)