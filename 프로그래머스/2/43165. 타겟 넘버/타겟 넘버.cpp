#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer=0;

void DFS (int depth, const int n, vector<int> &numbers, int result, int target){
    //base condition
    if(depth==n){
        if(result==target) answer++;
        return;
    }
    
    
    DFS(depth+1,n,numbers,result+numbers[depth], target);
    DFS(depth+1,n,numbers,result-numbers[depth], target);
    
}

int solution(vector<int> numbers, int target) {
    int n=numbers.size();
    int result=0;
    DFS (0, n, numbers, result, target);
    return answer;
}