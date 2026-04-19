#include <string>
#include <vector>
#include <queue>

using namespace std;
//queue에 트럭 넣기
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //int: 몸무게
    queue<int> trucks;
    int sum=0;
    int n=truck_weights.size();
    int i=0;
    
    //큐의 사이즈<=bridge_length && 지금총합+다음무게<=weight
    while(i<n){
        if(trucks.size()>=bridge_length)
        {
            sum-=trucks.front();
            trucks.pop();
        }
        
        
        if(sum+truck_weights[i]<=weight){
            //push
            sum+=truck_weights[i];
            trucks.push(truck_weights[i++]);
        }
        else{
            trucks.push(0);
        }
        answer++;
    }
 
    answer+=bridge_length;
    
    return answer;
}