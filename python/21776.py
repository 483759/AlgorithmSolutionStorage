from itertools import permutations
import sys

sys.stdin = open('input.txt','r')
n,c=map(int,sys.stdin.readline().split())

cards=[[]]
for i in range(n):
  cards.append(list(map(int,sys.stdin.readline().split()))[1:])

pmt=[]

for i in range(1,n+1):
  for _ in range(len(cards[i])):
    pmt.append(i)

pmt=list(permutations(pmt))
perm=[]
for p in pmt:
  li=[]
  dic=dict()
  for i in range(1,n+1):dic[i]=0
  for i in p:
    li.append(cards[i][dic[i]])
    dic[i]+=1
  perm.append(li)
perm=list(set(perm))

op=[[]]
for _ in range(c):
  op.append(list(map(str,sys.stdin.readline().split(','))))

def game(op, string):
  if op[:3]=='ADD':
    return string+op[4]
  else:
    if not op[4].isdigit() or int(op[4])<0 or int(op[4])>=len(string): return "ERROR"
    idx=int(op[4])
    return string[:idx]+string[idx+1:]

ans=set()
for p in perm:
  string=''
  for act in p:
    for a in op[act]:
      if string=='ERROR': break
      string=game(a, string)
  if len(string)==0:ans.add('EMPTY')
  else: ans.add(string)
for s in sorted(list(ans)):
  print(s)