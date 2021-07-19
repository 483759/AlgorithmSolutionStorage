import sys
from itertools import product

board=[[0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40],
       [0,2,4,6,8,10,13,16,19,25,30,35,40],
       [0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40],
       [0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40]]

def roll(dice, horse):
    horse[1]+=dice
    if horse[0]==0 and horse[1]%5 in [5,10,15]:
        horse[0]=horse[1]//5
    return horse

def horseOrder():
    li=[]
    for i in product([1,2,3,4], repeat=10):
        for h in i:
            print()

    return li


print(len(horseOrder()))
#dice=list(map(int,sys.stdin.readline().split()))

