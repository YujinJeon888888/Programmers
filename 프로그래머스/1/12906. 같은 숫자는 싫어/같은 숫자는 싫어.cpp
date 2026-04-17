#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//연속된 중복 제거 : unique함수
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    auto last = unique(arr.begin(),arr.end());
    arr.erase(last,arr.end());
    
    answer=arr;
    
    return answer;
}