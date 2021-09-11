import math

def isPrime(n):
  if n<=1: return False
  if n!=2 and n%2==0:
    return False
  for i in range(3, int(math.sqrt(n))+2, 2):
    if n%i==0:
      return False
  return True

def decToKNotation(n, k):
    ret=''
    while n!=0:
        ret=str(n%k)+ret
        n=n//k
    return ret

def solution(n, k):
    answer = 0
    kNum = decToKNotation(n, k)
    cdd=set(kNum.split('0'))
        
    for num in cdd:
      if len(num)==0 or isPrime(int(num))==False:
        continue
      
      for i in range(len(kNum)):
        if kNum[i:].startswith('0'+num+'0'):
          answer+=1
      
      # if '0'+num+'0' in kNum:
      #   answer+=1
        
      if kNum.startswith(num+'0'):
        answer+=1
      if kNum.endswith('0'+num):
        answer+=1
      if kNum==num:
        answer+=1
        
    return answer
  
# print(solution(437674, 3))
# print(solution(110011, 3))
# print(solution(110011, 4))
# print(solution(110011, 5))
# print(solution(110011, 6))
# print(solution(110011, 7))
# print(solution(110011, 8))
# print(solution(110011, 9))
# print(solution(110011, 10))
# print(solution(1, 10))
print(solution(449389,3))
print(solution(449389,4))
print(solution(449389,5))
print(solution(449389,6))
print(solution(449389,7))
print(solution(449389,8))
print(solution(449389,9))
print(solution(449389,10))