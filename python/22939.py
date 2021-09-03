import sys
from itertools import permutations

sys.stdin = open('python/input.txt', 'r')
input = sys.stdin.readline

n = int(input())
board = []
home = [0, 0]
cookie = [0, 0]
kinds = ['J', 'C', 'B', 'W']
field = ['Assassin', 'Healer', 'Mage', 'Tanker']
topping = [[] for _ in range(4)]


def dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])


for i in range(n):
    board.append(input())
    for j in range(n):
        if board[i][j] == 'H':
            home = [i, j]
        if board[i][j] == '#':
            cookie = [i, j]
        for k in range(4):
            if board[i][j] == kinds[k]:
                topping[k].append([i, j])

    minVal = 10**10
    ans = ''
    for k in range(4):
        perm = permutations(topping[k], 3)
        for p in perm:
            d = dist(home, p[0])+dist(p[0], p[1]) + \
                dist(p[1], p[2])+dist(p[2], cookie)
            if d < minVal:
                minVal = d
                ans = field[k]

print(ans)
