#include <string>
#include <vector>
#include <unordered_map> 
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //맵에, 해당 종류 옷 카운트 ++
    unordered_map<string,int> m;
    for(const auto val:clothes){
        m[val[1]]++;
    }
    //맵 순회하면서, 해당 카운트+1하여 순회한것끼리 곱하기. -1 (아무것도안입은거)
    for(const auto [type, count]: m){
        answer*=(count+1);
    }
    
    
    
    return answer-1;
}