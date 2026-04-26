#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int width=yellow;
    int height=1;
    
    //만들 수 있는 곱의 조합으로 다 해보기 (단, 가로가 긴 조합으로)
    while(true){
        if(yellow-(width*height)==0){
            //가로+2, 세로+2로 모서리해서 brown개수와 같으면 그게 정답.
            if(width*2 + height*2 + 4 == brown){
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }    
        }
        width-=1;
        height=yellow/width;
    }
         
    
    
    
    return answer;
}