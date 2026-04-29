#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
//운체처럼
//시간을 분단위로 바꾸기
//시작순서대로 일단 정렬

//반복문에서 시간카운트하고, 그때마다 해당 시간에 시작하는 애 있는지 체크
    //실행중이면, 시간카운트를 --하기. 
    //만약 있으면, 하던 애를 suspended queue에 넣기
    //하던 애 끝나면 queue에 있는 거 실행

struct plan{
    string name;
    int start;
    int playtime;
};

bool cmp(plan a, plan b){
    if(a.start!=b.start){
        return a.start<b.start;
    }
    return true;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int n=plans.size();
    vector<plan> _plans(n);
    
    for(int i=0;i<n;i++){
        int hour = stoi(plans[i][1].substr(0,2));
        int minutes=hour*60 + stoi(plans[i][1].substr(3,2));
        _plans[i].start=minutes;
        _plans[i].playtime=stoi(plans[i][2]);
        _plans[i].name=plans[i][0];
    }
    
    sort(_plans.begin(),_plans.end(),cmp);
    
    int time=_plans[0].start;
    
    deque<plan> execQ;
    
    while(n!=0){
        for(auto &plan:_plans){
            if(plan.start==time){
                execQ.push_front(plan);
            }
        }
        
        //실행
        if(!execQ.empty()){
            execQ.front().playtime = execQ.front().playtime-1;
            if(execQ.front().playtime==0){
                answer.push_back(execQ.front().name);
                execQ.pop_front();
                n--;
            }
        }
        time++;
    }
    
    return answer;
}