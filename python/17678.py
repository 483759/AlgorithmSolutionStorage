import datetime

def busSimulation(bustime, timetable, m, conn):
    idx=0       #현재 탈 수 있는 크루를 가리키는 인덱스
    for bus in bustime:     #버스 시간표에 있는 모든 버스에 대해
        for i in range(idx,idx+m):      #한 번에 최대 m명 탑승
            if i>=len(timetable):break      #인덱스 벗어나면 그만
            if timetable[i]<=bus:       #버스 시간 이하이면 탈 수 있다
                idx+=1
                if timetable[i]==conn:     #콘이 탑승했다면
                    if i==len(timetable)-1 or (i!=len(timetable)-1 and timetable[i+1]!=conn):
                        #가장 마지막에 탑승했거나
                        #다음 크루의 시간이 콘의 시간과 다를 경우에만(중복 시간이 있을 경우 콘이 가장 마지막이기 때문에)
                        return True
    return False
    #이 시간에는 콘은 탈 수 없다

def connSimulation(bustime, timetable,m):
    time=bustime[-1]    #콘이 탈 시간을 버스의 가장 마지막 운행시간부터 00:00시까지 시뮬레이션해줌
    while True:
        timetable.append(time)          #크루들의 목록에 콘을 추가해줌
        timetable=sorted(timetable)
        
        if busSimulation(bustime, timetable,m, time):   #만약 콘이 탈 수 있다면 현재 시간을 리턴해줌(가장 마지막 시간부터 감소시키기 때문에)
            return time
        
        timetable.remove(time)          #방금 추가했던 time을 빼줌
        if time.hour==0 and time.minute==0:     #00시 00분까지 시뮬레이션했다면 종료
            break

        time-=datetime.timedelta(minutes=1)     #1분 감소
    
    return time
    


def solution(n, t, m, timetable):
    busTime = []
    busTime.append(datetime.datetime.strptime('09:00','%H:%M'))     #bus의 첫 운행 시간

    for _ in range(n-1):        #n회 운행
        bus=busTime[-1]         #이전 시간 불러옴
        bus=bus+datetime.timedelta(minutes=t)   #이전 시간에 t분만큼 더해줌
        busTime.append(bus)     #busTIme 리스트에 추가
    
    for i in range(len(timetable)):     #대기하는 크루들을 datetime 객체로 변환해줌
        if timetable[i]=='24:00':
            timetable[i]=datetime.datetime.strptime('23:59','%H:%M')
            #입력 요구사항에 맞지 않는 입력이지만 처리해주지 않으면 22번 테스트케이스에서 틀림
        else:
            timetable[i]=datetime.datetime.strptime(timetable[i],'%H:%M')

    timetable=sorted(timetable)
    #크루들의 도착 시간을 정렬해줌
    
    return datetime.datetime.strftime(connSimulation(busTime,timetable,m), '%H:%M')
    #콘이 탈 수 있는 제일 늦은 시간을 문자열로 변환해서 반환한당

#print(solution(1,1,5,["08:00", "08:01", "08:02", "08:03"]))
#print(solution(2,10,2,['09:10', '09:09', '08:00']))
#print(solution(2,1,2,["09:00", "09:00", "09:00", "09:00"]))
#print(solution(1,1,5,["00:01", "00:01", "00:01", "00:01", "00:01"]))
#print(solution(1,1,1,["23:59"]))
print(solution(10,60,45,["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"]))

"""
import sys
import copy

class Time:
    h=0
    m=0

    def __init__(self,s):
        self.h=int(s[:2])
        self.m=int(s[3:])
    
    def plus(self, t):
        self.m+=t
        if self.m>=60:
            self.m-=60
            self.h+=1
        if self.h>=24:
            self.h-=24

    def minus(self):
        if self.h==0 and self.m==0: return False
        if self.m==0:
            self.h-=1
            self.m=59
        else: self.m-=1
        return True

    def same(self, other):
        if self.h==other.h and self.m==other.m: return True
        return False

    def __lt__(self, other):
        if self.h==other.h: return self.m<=other.m
        return self.h<=other.h

    def __repr__(self):
        return str(self.h)+':'+str(self.m)

    def st(self):
        s=''
        if self.h<10:s+='0'
        s+=str(self.h)
        s+=':'
        if self.m<10:s+='0'
        s+=str(self.m)
        return s


def solution(n, t, m, timetable):
    people=[]
    for k in timetable:
        people.append(Time(k))
    #people.sort()
    #print(people)

    last=Time('09:00')
    for _ in range(n-1): last.plus(t)
    #print(last)

    while True:
        #print(last)
        p=copy.deepcopy(people)
        p.append(last)
        p.sort()

        bus=Time('09:00')
        b=True
        for _ in range(n):
            for _ in range(m):
                if len(p)==0 or b==False: break
                if p[0].__lt__(bus):
                    #print(people[0])
                    k = p.pop(0)
                    if k.same(last):
                        if len(p)>=1 and p[0].same(last):continue
                        b=False
                        break

            bus.plus(t)
            #print(bus)

        if b==False:
            #print(last)
            break
        if not last.minus():break
    #print(arr)
    return last.st()
"""
#print(solution(	2, 1, 2, ["09:00", "09:00", "09:00", "09:00"]))
#print(solution(1, 1, 5,["08:00", "08:01", "08:02", "08:03"]))