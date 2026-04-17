#include <string>
#include <vector>
#include <stack>
using namespace std;



vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day;//이번 작업이 끝나는 데 걸리는 날짜
    int max_day=0;//현재 배포 그룹에서 가장 오래 걸리는 대장의 날짜
    
    for(int i=0;i<progresses.size();i++){
        //완료 날짜 계산
        day=(99-progresses[i])/speeds[i]+1;
        
        //배포 그룹 묶기
        //아예 처음이거나, 이번 작업이 이전 대장보다 오래 걸린다면?
        if(answer.empty()||max_day<day){
            //앞기차는 보내고 내가 새로운 대장이 되어 새 배포그룹을 만듦.
            answer.push_back(1);
        }
        else{
            //지금 작업이 대장보다 일찍 끝난다면
            //대장 나갈 때 같이 나감
            ++answer.back();
        }
        
        //대장 정보 갱신
        //만약 이번 작업이 지금까지의 대장보다 늦게 끝난다면
        //이제부터 얘가 대장임
        if(max_day<day){
            max_day=day;
        }
    }
    
    return answer;
}