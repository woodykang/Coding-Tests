#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands);
vector<int> slice_array(vector<int> array, int start_index, int end_index);
vector<int> sort(vector<int> array);
int kth_number(vector<int> array, vector<int> command);

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer = {};
    int n = commands.size();
    
    for(int i = 0; i < n; i++)
    {
        answer.push_back( kth_number(array, commands[i]) );
    }

    return answer;
}

int kth_number(vector<int> array, vector<int> command)
{
    vector<int> sliced_array;
    int kth;                    // kth number of the sliced array 
    int i = command[0] - 1;     // start index
    int j = command[1];         // end   index
    int k = command[2] - 1;     // k
    
    sliced_array = slice_array(array, i, j);
    
    std::sort(sliced_array.begin(), sliced_array.end());
    kth = sliced_array[k];
    
    return kth;
}

vector<int> slice_array(vector<int> array, int start_index, int end_index)
{
    vector<int> sliced_array = {};
    for(int i = start_index; i < end_index; i++)
    {
        sliced_array.push_back(array[i]);
    }
    
    return sliced_array;
}
