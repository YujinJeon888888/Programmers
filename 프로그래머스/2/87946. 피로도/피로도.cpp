#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n=dungeons.size();
    int kCache=k;
    sort(dungeons.begin(),dungeons.end());
    
    do{
        int dungeonCount=0;
        k=kCache;
       for(int i=0;i<n;i++){
           if(dungeons[i][0]<=k&&dungeons[i][1]<=k){
               k-=dungeons[i][1];
               dungeonCount++;
           }
       }
        answer=max(answer,dungeonCount);
    
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    //던전 조합 전부 시도
        //현재 피로도보다 최소 필요 피로도가 낮고 현재 피로도가 소모 피로도보다 높으면 소모시키기
        
        //최대 던전 수 갱신
    
    
    
    return answer;
}