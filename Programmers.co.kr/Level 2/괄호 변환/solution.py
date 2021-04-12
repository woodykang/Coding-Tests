# 균형잡힌 괄호 문자열인지 확인
def check_pair(p):
    if p.count('(') == p.count(')'):
        return True

    return False

# 올바른 괄호 문자열인지 확인
def check_right(p):
    n = len(p)
    num_op = 0          # number of open parentheses
    num_cl = 0          # number of close parentheses
    for i in range(n):
        # '('인지 ')'인지 판단 후 개수 세기
        if p[i] == '(':
            num_op += 1
        else:
            num_cl += 1

        # ')' 개수가 '('보다 많아지는 순간이 있으면 무조건 올바르지 않은 괄호 문자연
        if num_cl > num_op:
            return False

    # 마지막에 '('와 ')'의 개수가 같아야함
    return num_op == num_cl

def solution(p):
    # 1. 빈 문자열일 경우 빈 분자열을 반환
    if p == "":
        return p
    # 이미 올바른 괄호 문자열일 경우 그대로 반환
    if check_right(p):
        return p

    # 2. 문자열을 u, v로 분리
    for i in range(1, int(len(p)/2) + 1):
        if check_pair(p[:2*i]):
            u = p[   :2*i]
            v = p[2*i:   ]
            break

    # 3. u가 올바른 괄호 문자열이라면 v에 대해 1단계부터 다시 수행
    if check_right(u):
        v = solution(v)
        answer = u + v

    # 4. u가 올바른 괄호 문자열이 아닐 경우
    else:
        # 4-1. 빈 문자열에 대해 '('를 붙인다.
        answer = "("
        # 4-2. v에 대해 재귀적으로 수행한 문자열을 붙인다.
        answer = answer + solution(v)

        # 4-3. ')'를 붙이낟.
        answer = answer + ")"

        # 4-4. u의 첫번째와 마지막 문자를 제거하고
        u = u[1:-1]
        # 나머지 문자열의 괄호를 뒤집어서 붙인다.
        for i in range(len(u)):
            if u[i] == '(':
                answer = answer + ")"
            else:
                answer = answer + "("

    return answer
