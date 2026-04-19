#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//앞자리가 큰 순서대로 정렬.
bool cmp(int a,int b){  
    string aString=to_string(a);
    string bString=to_string(b);
    
    string ab = aString + bString;
    string ba = bString + aString;
    
    return ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),cmp);
    for(const auto val: numbers){
        answer+=to_string(val);
    }
    if (answer[0] == '0') return "0";
    return answer;
}