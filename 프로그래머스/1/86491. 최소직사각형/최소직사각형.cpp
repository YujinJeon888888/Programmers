#include <string>
#include <vector>

using namespace std;
//[긴 쪽]들을 한 군데로 몰고, [짧은 쪽]들을 다른 한 군데로 몰아서 각각의 최댓값을 구하면 끝
int solution(vector<vector<int>> sizes) {
    int maxLong=0;
    int maxShort=0;
    
    for(auto& card: sizes){
        //각 명함에서 긴 쪽과 짧은 쪽 구분
        int longSide=max(card[0],card[1]);
        int shortSide=min(card[0],card[1]);
        
        //긴쪽에서 가장 긴 애, 짧은쪽에서 가장 긴 애를 찾음
        maxLong=max(maxLong,longSide);
        maxShort=max(maxShort,shortSide);
    }
    
    
    
    return maxLong*maxShort;
}