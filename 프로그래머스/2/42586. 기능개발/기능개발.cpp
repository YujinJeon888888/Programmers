#include <string>
#include <vector>
#include <stack>
using namespace std;

struct process{
    int progress;
    int speed;
};

//각 작업속도 맞게, 구조체를 만든다. 
//그 구조체대로, while(100인애가 없을때까지 더한다.)

//스택에 넣는 건, index를 옮겨가며,앞 순서가 100이상이 될 시 뒷순서가 100이상인 동안 계속 스택에 넣는다. 
//그리고 정답에 스택크기를 넣고, 스택을 모두 팝한다.

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n=progresses.size();
    vector<process> processArr(n+1);
    
    for(int i=1;i<=n;i++){
        processArr[i].progress=progresses[i-1];
        processArr[i].speed=speeds[i-1];
    }
    
    int index=1;
    
    while(true){
        //TODO: end condition: 모두 100이상이면 break;
        bool endCondition=true;
        for(int i=1;i<=n;i++){
            if(processArr[i].progress<100){
                endCondition=false;
            }
        }
        
        if(endCondition){
            break;
        }
        
        //1초마다(WHILE문마다) 작업량만큼 더하기
        for(int i=1;i<=n;i++){
            processArr[i].progress+=processArr[i].speed;
        }
        
        stack<int> succeedIndexStack;
        
        //표준인덱스 기준으로 100이상이면
        while(index<=n&&processArr[index].progress>=100)
        {
            //작업완료에 넣고
            succeedIndexStack.push(index);
            //다음것도 확인 위해 인덱스 이동
            index++;
        }
        
        
        //작업완료된 게 있으면
        if(succeedIndexStack.size()!=0){
            //ANSWER에 작업완료된 양만큼 넣기
            answer.push_back(succeedIndexStack.size());    
        }
    }    
    
    
    return answer;
}