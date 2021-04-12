#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool is_prime(int num)
{
    if(!num)        return false;
    if(num == 1)    return true;
    
    for(inti = 2; i < pow(num, 0.5) + 1; i++)
    {
        if(num % i == 0)    return false;
    }
    
    return true;
}

vector<string> create_combination(string numbers)
{
    if(numbers.size() == 1)
    {
        return vector(stoi(numbers));
    }
    
    vector<int> combination_array;
    vector<int> result_array;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string excluded_number = numbers.substr(0, i) + numbers.substr(i);
        vector<string> combinated_array = create_combination(excluded_number);
        
        for(int j = 0; j < combinated_array.size(); j++)
        {
            result_array.push_back(numbers[i] + combinated_array[j]);
            result_array.push_back(combianted_array[j]);
        }
        
        return result_array;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    if(numbers.size() == 1) return int(is_prime(stoi(numbers)));
    
    
    return answer;
}
