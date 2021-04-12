def solution(n):
    answer = ''
    
    q = (n - 1) // 3
    r = (n - 1) % 3
    
    if q > 0:
        m = solution(q)
        answer = answer + m
    
    answer = answer + str(2**(r))
        
    return answer
