#include <string>
#include <vector>
#include <stack>
using namespace std;

//목적: 가격이 떨어지지 않은 기간 구하기
//스택: 작은애만 남게.

//루프마다 푸시하고.
vector<int> solution(vector<int> prices) {
    
    stack<int> s;
    int n=prices.size();
    vector<int> answer(n);
    
    for(int i=n-1;i>=0;i--){
        
        while(!s.empty() && prices[s.top()]>=prices[i]){
            s.pop();
        }
        
        if(s.empty()){
            answer[i]=n-1-i;
        }
        else{
            answer[i]=s.top()-i;
        }
        
        s.push(i);
    }
    
    
    
        
    return answer;
}