import sys

sys.stdin=open('input.txt','r')
n,d,k,c=map(int,sys.stdin.readline().split())
sushi=[]
for _ in range(n):
    sushi.append(int(sys.stdin.readline()))
keys=dict.fromkeys(set(sushi),0)
if keys.get(c) is None:keys[c]=0

left=0
right=0
cnt=0
kind=0
answer=0
while left!=n-1:
    #print(str(left)+" "+str(right))
    if cnt>=k:
        keys[sushi[left]]-=1
        if keys[sushi[left]]==0:
            kind-=1

        left=(left+1)%n
        cnt-=1
    else:
        if keys[sushi[right]]==0:
            kind+=1
        keys[sushi[right]]+=1
        right=(right+1)%n
        cnt+=1
    if kind>=answer:
        answer=kind
        if keys[c]==0:answer+=1
#print(sushi)
print(answer)