#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
1. 찍는 패턴 확인하기(몇번인덱스부터 몇번인덱스까지가 패턴인지)

2. 그거 나머지로 순회해가면서 정답 개수 확인

3. 각 학생마다 맞힌 회수 저장해두고 MAX면 정답에 MAX개수인 학생 인덱스 전부넣기
*/
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3,0);
    
    //패턴 저장
    vector<int> p1= {1,2,3,4,5};
    vector<int> p2= {2,1,2,3,2,4,2,5};
    vector<int> p3={3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0;i<answers.size();i++){
        if(answers[i]==p1[i%p1.size()]) score[0]++;
        if(answers[i]==p2[i%p2.size()]) score[1]++;
        if(answers[i]==p3[i%p3.size()]) score[2]++;
    }
    
    int maxScore = *max_element(score.begin(), score.end());
    
    for(int i=0;i<3;i++){
        if(maxScore==score[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}