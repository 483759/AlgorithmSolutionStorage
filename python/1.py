def solution(s):
    answer = 0
    token=["zero","one","two","three","four","five","six","seven","eight","nine"]

    for i in range(len(token)):
        s=s.replace(token[i], str(i))
    print(s)
    return answer

print(solution("2three45sixseven"))