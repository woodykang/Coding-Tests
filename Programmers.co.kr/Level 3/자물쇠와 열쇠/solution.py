def solution(key, lock):
    N = len(key[0])         # key  is N x N array
    M = len(lock[0])        # lock is M x M array

    for rot_time in range(3):       # rotate key 3 times

        ## Shifting key
        for x in range(1, 2*N - 1):         # shift in x axis
            for y in range(1, 2*N - 1):     # shift in y axis

                result = True
                for i in range(M):
                    for j in range(M):
                        ## XOR to elements of key and lock
                        if (i in range( max(0, x - N), min(x, N) )) & (j in range( max(0, y - N), min(y, N) )):
                            result &= key[N - x + i][N - y + j] ^ lock[i][j]

                        else:
                            result &= lock[i][j]
                
                if result:
                    return True
        
        ## Rotate  key
        key = [[key[N - 1 - j][i] for j in range(N)] for i in range(N)]

    return False
