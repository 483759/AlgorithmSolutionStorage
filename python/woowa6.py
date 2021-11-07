import datetime
from datetime import timedelta

def timeToDecimal(time):
  if time.endswith("AM"):
    return int(time[:-2])
  return int(time[:-2])+12

def solution(time, plans):
    answer = ''
    mon = [13, 18]
    fri = [9.5, 18]
    
    
    for plan in plans:
      des, s, f = plan
      vacation = 0
      s, f = timeToDecimal(s), timeToDecimal(f)
      
      if s<fri[0]:
        vacation += fri[1]-fri[0]
      elif s<fri[1]:
        vacation += fri[1]-s
        
      if f<mon[0]:
        vacation += 0
      elif f>=mon[1]:
        vacation += mon[1]-mon[0]
      else:
        vacation += f-mon[0]
        
      if vacation>time:
        break
      else:
        time-=vacation
        answer=des
    
    return answer
  
print(solution(3.5,	[ ["홍콩", "11PM", "9AM"], ["엘에이", "3PM", "2PM"] ]))