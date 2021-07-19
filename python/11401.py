import sys

n,k=map(int,sys.stdin.readline().split())
MOD=1000000007
fact=[0,1]

for i in range(2,n+1):
    fact.append(((i%MOD)*(fact[-1]%MOD))%MOD)
a=fact[n]
b=((fact[n-k]%MOD)*(fact[k]%MOD))%MOD

power=[b]
for _ in range(30):
    power.append(((power[-1]%MOD)*(power[-1]%MOD))%MOD)

c=1
d=MOD-2
for i in range(MOD):
    if d==0:break
    if d%2 !=0:
        c=((c%MOD)*(power[i]%MOD))%MOD
    d>>=1

ans=(a%MOD)*(c%MOD)%MOD
if k==0 or k==n:print(1)
else: print(ans)