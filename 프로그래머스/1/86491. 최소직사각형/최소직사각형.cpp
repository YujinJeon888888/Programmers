#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int n=sizes.size();
    int maxLen=-1;
    int maxI=-1;
    bool isMaxHeight=false;
    
    //가로 세로 중 max를 뽑기
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(maxLen<sizes[i][j]){
                maxLen=sizes[i][j];
                maxI=i;
                if(j==1){
                    isMaxHeight=true;
                }
                else{
                    isMaxHeight=false;
                }
            }
        }
    }
    
    //max인 애 제외하고, 
    if(isMaxHeight){
        for(int i=0;i<n;i++){
            if(i==maxI){
                continue;
            }
            //가로가 세로보다 크면 스왑
            if(sizes[i][0]>sizes[i][1]){
                swap(sizes[i][0],sizes[i][1]);
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(i==maxI){
                continue;
            }
            //세로가 가로보다 크면 스왑
            if(sizes[i][0]<sizes[i][1]){
                swap(sizes[i][0],sizes[i][1]);
            }
        }
    }
    
    //answer: 순회해서 가로max, 세로max 구하고 곱하기
    int maxWid=-1;
    int maxHei=-1;
    for(int i=0;i<n;i++){
        maxWid=max(maxWid,sizes[i][0]);
        maxHei=max(maxHei,sizes[i][1]);
    }
    
    answer=maxHei*maxWid;
    
    return answer;
}