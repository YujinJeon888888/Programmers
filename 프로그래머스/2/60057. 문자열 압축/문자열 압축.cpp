#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int n = s.length();
    if (n == 1) return 1; // 길이가 1인 경우 예외 처리

    int answer = n; // 최악의 경우(압축 안 됨) 원본 길이로 초기화

    // 1부터 n/2 단위까지 모두 시도
    for (int i = 1; i <= n / 2; i++) {
        string compressed = "";
        string prev = s.substr(0, i); // 첫 번째 조각
        int count = 1;

        // i 단위로 문자열을 잘라가며 비교
        for (int j = i; j < n; j += i) {
            string current = s.substr(j, i);

            if (prev == current) {
                count++; // 같은 패턴이면 카운트 증가
            } else {
                // 패턴이 달라지면 지금까지의 결과 기록
                if (count > 1) compressed += to_string(count);
                compressed += prev;
                
                prev = current; // 기준 조각 교체
                count = 1;      // 카운트 초기화
            }
        }

        // 마지막에 남은 조각 처리
        if (count > 1) compressed += to_string(count);
        compressed += prev;

        // 기존 최솟값과 비교하여 갱신
        answer = min(answer, (int)compressed.length());
    }

    return answer;
}