import sys
n=['0','1','2','3','4','5','6','7','8','9']
for i in range(97,123):
    n.append(chr(i))

a,b=map(str,sys.stdin.readline().split())
def toNum(c):
    global n
    if c.isdigit():
        return int(c)
    else: return ord(c)-ord('a')+10

def KtoX(num, k):
    n=0
    t=1
    for i in range(len(num)-1,-1,-1):
        if toNum(num[i])>=k:return -1
        n+=toNum(num[i])*t
        t*=k
    return n

answer=[]
for A in range(2,37):
    for B in range(2,37):
        if A==B: continue
        xa=KtoX(a,A)
        xb=KtoX(b,B)
        if xa==-1 or xb==-1:continue
        elif xa==xb and xa<2**63:
            answer.append([xa,A,B])

if len(answer)>1:print('Multiple')
elif len(answer)==0:print('Impossible')
else: 
    print(str(answer[0][0])+' '+str(answer[0][1])+' '+str(answer[0][2]))
