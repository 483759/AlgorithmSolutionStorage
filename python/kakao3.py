import datetime
import math

def solution(fees, records):
    answer = []
    parking_time=dict()
    parking_lot=dict()
    
    for r in records:
        info=r.split(' ')
        if info[2]=='IN':
          parking_lot[info[1]]=[True, datetime.datetime.strptime(info[0],'%H:%M')]
        
        if info[2]=='OUT':
          out_time=datetime.datetime.strptime(info[0],'%H:%M')
          parking_lot[info[1]][0]=False
          if parking_time.get(info[1])==None:
            parking_time[info[1]]=0
          parking_time[info[1]]+=(out_time-parking_lot[info[1]][1]).seconds//60
    
    for car, info in parking_lot.items():
      if parking_time.get(car)==None:
        parking_time[car]=0
      if info[0]:
        parking_time[car]+=(datetime.datetime.strptime('23:59','%H:%M')-info[1]).seconds//60
    
    for key, val in parking_time.items():
      if val<=fees[0]:
        answer.append([key, fees[1]])
      else:
        additional=math.ceil((val-fees[0])/fees[2])*fees[3]
        answer.append([key, fees[1]+additional])
    
    answer.sort(key=lambda x:x[0])
    
    return [val[1] for val in answer]
  
# print(solution([180, 5000, 10, 600],	["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
print(solution([120, 0, 60, 591],["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"]))
# print(solution([1, 461, 1, 10],["00:00 1234 IN"]))