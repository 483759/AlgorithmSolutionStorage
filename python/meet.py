from itertools import combinations


def solution(line):
    comb = list(combinations(line, 2))
    s = set()
    bound = [[1000, 1000], [-1000, -1000]]

    for c in comb:
        A, B, E, C, D, F = c[0][0], c[0][1], c[0][2], c[1][0], c[1][1], c[1][2]
        if (A*D-B*C) == 0:
            continue
        if (B*F-E*D) % (A*D-B*C) != 0 or (E*C-A*F) % (A*D-B*C) != 0:
            continue

        X = (B*F-E*D) // (A*D-B*C)
        Y = (E*C-A*F) // (A*D-B*C)
        bound[0] = [min(bound[0][0], X), min(bound[0][1], Y)]
        bound[1] = [max(bound[1][0], X), max(bound[1][1], Y)]

        s.add(((B*F-E*D) // (A*D-B*C), (E*C-A*F) // (A*D-B*C)))

    answer = [['.' for _ in range(bound[1][0]-bound[0][0]+1)]
              for _ in range(bound[1][1]-bound[0][1]+1)]

    for p in s:
        answer[bound[1][1]-p[1]][p[0]-bound[0][0]] = '*'

    for i in range(len(answer)):
        answer[i] = ''.join(answer[i])

    return answer


# print(solution([[2, -1, 4], [-2, -1, 4],[0, -1, 1], [5, -8, -12], [5, 8, 12]]))
# print(solution([[0, 1, -1], [1, 0, -1], [1, 0, 1]]))
# print(solution([[1, -1, 0], [2, -1, 0]]))
print(solution([[1, -1, 0], [2, -1, 0], [4, -1, 0]]))
