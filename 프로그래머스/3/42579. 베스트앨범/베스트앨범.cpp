#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 1. 데이터 담기
    unordered_map<string, int> total_plays; // 장르별 총 재생 수
    unordered_map<string, vector<pair<int, int>>> songs_per_genre; // 장르별 {재생수, 번호} 목록
    
    for (int i = 0; i < genres.size(); i++) {
        total_plays[genres[i]] += plays[i];
        songs_per_genre[genres[i]].push_back({plays[i], i});
    }

    // 2. 장르를 총 재생 수 순으로 정렬하기 위해 벡터로 복사
    vector<pair<string, int>> sorted_genres(total_plays.begin(), total_plays.end());
    sort(sorted_genres.begin(), sorted_genres.end(), [](auto a, auto b) {
        return a.second > b.second; // 재생 수 내림차순
    });

    // 3. 각 장르를 돌며 노래 정렬 후 2개씩 선택
    for (auto& g : sorted_genres) {
        string genre_name = g.first;
        auto& songs = songs_per_genre[genre_name];

        // 장르 내 노래 정렬
        sort(songs.begin(), songs.end(), [](auto a, auto b) {
            if (a.first == b.first) return a.second < b.second; // 재생 수 같으면 번호 작은 순
            return a.first > b.first; // 재생 수 많은 순
        });

        // 최대 2개까지 정답에 추가
        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}