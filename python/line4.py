def eratos(prime, n):
  check=[False, False]+[True]*(n+1)
  for i in range(2, n+1):
    if check[i]:
      prime.append(i)
      for j in range(2*i, n+1, i):
        check[j]=False

def solution(n):
    answer = []
    index=[i-1 for i in range(n+1)]
    prime=[]
    eratos(prime, n)
    len, p=n, n
    
    for i in prime:
      if len%i==0 and 
    
    
    return answer
  
print(solution(12))