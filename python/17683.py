import datetime

def solution(lyrics, musicinfos):
    answer="(None)"
    dic={'C#':'c', 'D#':'d', "F#":'f', 'G#':'g', 'A#': 'a'}
    maxTime=0
    
    for key, val in dic.items():
        lyrics=lyrics.replace(key, val)

    for music in musicinfos:
        info=music.split(',')
        for key, val in dic.items():
            info[3]=info[3].replace(key, val)
        #print(info[3])

        time=[]

        for i in range(2):
            time.append(datetime.datetime.strptime(info[i],'%H:%M'))
        playtime=int(((time[1]-time[0]).seconds)/60)
        #print(playtime)
        
        p=playtime
        play=""

        while p>len(info[3]):
            play+=info[3]
            p-=len(info[3])
        play+=info[3][:p]
        #print(play)

        if lyrics in play:
            if playtime > maxTime:
                answer=info[2]
                maxTime=playtime       
        
    return answer

print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))

"""
import datetime
import re
import math

def solution(lyrics, musicinfos):
    answer = ['',0]

    for st in musicinfos:
        info=st.split(',')
        t=[]

        for i in range(2):
            t.append(datetime.datetime.strptime(info[i],'%H:%M'))
        pt=round((t[1]-t[0]).seconds/60)

        melody=[]
        for i in info[3]:
            if i=='#':
                melody[-1]+='#'
            else: melody.append(i)
        
        M=''
        for i in range(pt):
            M+=melody[i%len(melody)]

        for i in range(len(M)-len(lyrics)+1):
            if M[i]=='#':continue
            t=M[i:i+len(lyrics)]
            if t==lyrics:
                if i<len(M)-len(lyrics) and M[i+len(lyrics)]=='#':continue
                if pt>int(answer[1]):
                    answer[0]=info[2]
                    answer[1]=pt

    if answer[0]=='': return '(None)'
    return answer[0]

"""