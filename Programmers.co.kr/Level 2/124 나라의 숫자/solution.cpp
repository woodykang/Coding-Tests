#include <math.h>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int q = (n - 1)/3;
    int r = (n - 1) - 3*q;
    
    if(q > 0)
    {
        answer = answer + solution(q);
    }
    
    answer = answer + std::to_string(int(pow(2, r)));
    
    return answer;
}
