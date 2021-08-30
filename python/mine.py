def safe(r, c, w, h):
    return r >= 0 and r < h and c >= 0 and c < w


def find(board, r, c, answer):
    if board[r][c] == 'M':
        for i in range(len(board[0])):
            for j in range(len(board)):
                if board[i][j] == 'M':
                    answer[i][j] = 'M'
                else:
                    answer[i][j] = 'E'
        answer[r][c] = 'X'
    else:
        dc = [1, 1, 1, 0, -1, -1, -1, 0]
        dr = [-1, 0, 1, 1, 1, 0, -1, -1]
        cnt = 0
        s = []

        for d in range(8):
            nr = r+dr[d]
            nc = c+dc[d]
            if not safe(nr, nc, len(board[0]), len(board)):
                continue

            if board[nr][nc] == 'M':
                cnt += 1
            elif answer[nr][nc] == '_':
                s.append([nr, nc])

        if cnt > 0:
            answer[r][c] = str(cnt)
            return
        else:
            answer[r][c] = 'B'
            for p in s:
                find(board, p[0], p[1], answer)


def solution(board, y, x):
    answer = [['_' for _ in range(len(board[0]))] for _ in range(len(board))]

    find(board, y, x, answer)

    for i in range(len(answer)):
        for j in range(len(answer[i])):
            if answer[i][j] == '_':
                answer[i][j] = 'E'
        answer[i] = ''.join(answer[i])
        print(answer[i])
    return answer


# print(solution(["EEEEE", 'EEMEE', 'EEEEE', 'EEEEE'], 2, 0))

# print(solution(["MME", 'EEE', 'EME'], 0, 2))
print(solution(['EEEEMEEEE', 'EEEEEEEEM', 'EEEEEEMEE', 'EEEEEEEEE',
      'EEMEEEEEM', 'EEEEEEEEE', 'MEEEEEMEE', 'EEEMEEEEE', 'MEEEEEMEE'], 0, 0))
