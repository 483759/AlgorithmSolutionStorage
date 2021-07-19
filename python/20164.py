import sys

n=sys.stdin.readline().strip()
answer=[10**10,0]

def solve(k, val):
    global answer
    for i in k:
        if int(i)%2==1:
            val+=1
    if len(k)==1:
        if val<answer[0]:answer[0]=val
        if val>answer[1]:answer[1]=val
        return
    elif len(k)==2:
        solve(str(int(k[:1])+int(k[1:])),val)
        return
    for i in range(1,len(k)-1):
        for j in range(i+1, len(k)):
            solve(str(int(k[:i])+int(k[i:j])+int(k[j:])),val)
    return
solve(n,0)
print(str(answer[0])+' '+str(answer[1]))