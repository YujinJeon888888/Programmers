#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

void MakeSosu(vector<bool> & sosu){
    sosu[0]=sosu[1]=false;
    int n=sosu.size();
    for(int i=2;i*i<=n;i++){
        if(sosu[i]){
            for(int j=i*i;j<n;j+=i){
                sosu[j]=false;
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> sosu(10000000,true);
    MakeSosu(sosu);
    
    sort(numbers.begin(),numbers.end());
    
    set<int> s;
    
    do{
        string num="";
        for(int i=0;i<numbers.size();i++){
            num+=numbers[i];
            s.insert(stoi(num));
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    for(int n:s){
        if(sosu[n]){
            answer++;
        }
    }
    
    return answer;
}