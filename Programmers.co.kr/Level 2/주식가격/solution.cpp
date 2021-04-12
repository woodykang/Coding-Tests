#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    
    for(int i = 0; i < prices.size() - 1; i++)
    {
        answer.push_back(0);
        
        for(int j = i + 1; j < prices.size(); j++ )
        {
            answer[i]++;
            if(prices[i] > prices[j])
            {
                break;
            }
        }
    }
    
    answer.push_back(0);
    return answer;
}
