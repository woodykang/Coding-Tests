def solution(prices):
    answer = []
    
    for i in range(len(prices) - 1):
        answer.append(0)
        for j in range(i + 1, len(prices)):
            answer[i] += 1
            if prices[i] > prices[j]:
                break

    answer.append(0)
    return answer
