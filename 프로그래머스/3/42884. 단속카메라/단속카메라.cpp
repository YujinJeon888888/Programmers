#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
진입점을 내림차순으로 정렬

첫번째 요소의 나가는 점에 카메라 설치
반복: 
	다음 요소를 순회하며, 그 요소의 중간(첫~끝)에 카메라가 있으면 스킵
	없으면 그 요소의 나가는 점에 카메라 설치
*/



int solution(vector<vector<int>> routes) {
    int answer=0;
    
    // 1. 진입 지점(index 0) 기준으로 내림차순 정렬
    // vector<int>끼리 비교할 때 greater를 쓰면 첫 번째 원소부터 내림차순 정렬해줍니다.
    sort(routes.begin(), routes.end(), greater<vector<int>>());

    // 2. 마지막 카메라 위치 초기화 (좌표 범위가 -30,000 ~ 30,000이므로 넉넉하게)
    // 오른쪽에서 왼쪽으로 훑을 거니까 아주 큰 값으로 시작합니다.
    int lastCameraPos = 30001; 

    // 3. 차량들을 하나씩 순회
    for (const auto& route : routes) {
        // 현재 카메라가 이 차량의 탈출 지점(route[1])보다 오른쪽에 있다면?
        // 즉, 이 차량의 경로[-20, -15]가 카메라 위치[-5]를 포함하지 못한다면!
        if (lastCameraPos > route[1]) {
            answer++; // 카메라 새로 설치
            // 유진님 전략: 가장 효율적인 '진입 지점'에 설치
            lastCameraPos = route[0]; 
        }
        // else: 카메라가 route[1]보다 왼쪽에 있거나 같다면 이미 찍힌 거니 통과!
    }

    return answer;
}