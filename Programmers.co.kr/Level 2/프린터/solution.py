def solution(priorities, location):
    order = 1
    while len(priorities) != 0:                     # iterates until there is no element in priorities
        if priorities[0] == max(priorities):        # the front-most document will be printed
            if location == 0:                       # the front-most document is the one we want to track
                return order
            
            else:                                   # the front-most document is NOT the one we want to track
                priorities.pop(0)                   # front-most is removed
                order += 1
                location -= 1                       # the work we want to track is moved to the front by 1
                
        else:
            priorities.append(priorities.pop(0))    # send the first element to the last
            if location == 0:
                location = len(priorities) - 1      # new location of the work is sent to the last
                
            else:
                location -= 1                       # the work we want to track is moved to the front by 1
    
    answer = 0
    return answer
