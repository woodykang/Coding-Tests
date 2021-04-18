def solution(key, lock):
    M = len(key[0])         # key  is M x M array
    N = len(lock[0])        # lock is N x N array

    for rot_time in range(4):       # rotate key 3 times

        ## Shifting key
        for x in range(1, N + M + 1):         # shift in x axis
            for y in range(1, N + M + 1):     # shift in y axis

                ## XOR operation to elements of rotated & shifted key and lock
                result = True
                for i in range(N):
                    for j in range(N):
                        ## Case 1: rotated & shifted key and lock overlap
                        if (i in range( max(0, x - M), min(x, N) )) & (j in range( max(0, y - M), min(y, N) )):
                            result &= key[M - x + i][M - y + j] ^ lock[i][j]

                        ## Case 2: key and lock does not overlap
                        else:
                            result &= lock[i][j]
                
                ## Return True if result == True
                if result:
                    return True
        
        ## Rotate  key
        key = [[key[M - 1 - j][i] for j in range(M)] for i in range(M)]

    return False
