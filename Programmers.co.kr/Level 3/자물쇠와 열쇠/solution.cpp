#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key[0].size();        // key is  M x M array
    int N = lock[0].size();       // lock is N x N array
    
    // Rotate key 4 times.
    for(int rot_time = 0; rot_time < 4; rot_time++)
    {
        // Shift key.
        for(int x = 0; x < N + M + 1; x++)      // shifting in x axis
        {
            for(int y = 0; y < N + M + 1; y++)  // shifting in y axis
            {
                // XOR operation to elements of rotated & shifted key and lock.
                bool result = true;
                for(int i = 0; i < N; i++)
                {
                    for(int j = 0; j < N; j++)
                    {
                        // Case 1: rotated & shifted key and lock overlap
                        if( (i >= max(0, x - M)) & (i < min(x, N)) & (j >= max(0, y - M)) & (j < min(y, N)) )
                        {
                            result &= key[M - x + i][M - y + j] ^ lock[i][j];
                        }
                        
                        // Case 2: key and lock does not overlap
                        else result &= lock[i][j];
                    }
                }
                
                if(result) return true;
            }
                
        }
        
        // Rotate key.
        vector<vector<int>> rotated_key = key;
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < M; j++)
            {
                rotated_key[i][j] = key[M - 1 - j][i];
            }
        }
                                     
        key = rotated_key;
    }
    
    return false;
}
