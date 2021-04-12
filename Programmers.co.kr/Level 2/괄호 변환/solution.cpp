#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 균형잡힌 괄호 문자열인지 확인
bool check_pair(string p)
{
    if(std::count(p.begin(), p.end(), '(') == std::count(p.begin(), p.end(), ')'))
    {
        return true;
    }
    return false;
}

// 올바른 괄호 문자열인지 확인
bool check_right(string p)
{
    int n = p.size();
    int num_op = 0;
    int num_cl = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(p[i] == '(') num_op++;
        else            num_cl++;
        
        if(num_cl > num_op) return false;
    }
    
    return num_op == num_cl;
}

string solution(string p)
{
    string answer = "";
    string u, v;
    
    // 1. 빈 문자열일 경우 빈 문자열을 반환
    if(p=="")   return p;
    
    // 이미 올바른 괄호 문자열일 경우 그대로 반환
    if(check_right(p)) return p;
    
    // 2. 문자열을 u, v로 분리
    for(int i = 1; i < int(p.size()/2) + 1; i++)
    {
        if(check_pair(p.substr(0, 2*i)))
        {
            u = p.substr(0, 2*i);
            v = p.substr(2*i, p.size());
            break;
        }
    }
    
    // 3. u가 올바른 괄호 문자열이라면 v에 대해 1단계부터 다시  수행
    if(check_right(u))
    {
        v = solution(v);
        answer = u + v;
    }
    
    // 4. u가 올바른 괄호 문자열이 아닐 경우
    else
    {
        // 4-1. 빈 문자열에 대해 '('를 붙인다.
        answer = '(';
        
        // 4-2. v에 대해 재귀적으로 수행한 문자열을 붙인다.
        answer = answer + solution(v);
        
        // 4-3. ')'를 붙인다.
        answer = answer + ")";
        
        // 4-4. u의 첫 번째와 마지막 문자를 제거하고
        u = u.substr(1, u.size() - 2);
        // 나머지 문자열의 괄호를 뒤집어서 붙인다.
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') answer = answer + ')';
            else            answer = answer + '(';
        }
    }
    return answer;
}
