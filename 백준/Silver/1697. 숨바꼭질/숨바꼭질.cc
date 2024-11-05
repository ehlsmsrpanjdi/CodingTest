#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dist[100001]; // 최대 100000까지 확인하기 위해 크기를 100001로 설정
bool visit[100001]; // 방문 여부 배열
queue<int> qu;

int main() {
    int x, y;
    cin >> x >> y;

    memset(dist, -1, sizeof(dist)); // 거리 배열 초기화
    qu.push(x);
    dist[x] = 0; // 시작 위치의 거리 0으로 초기화

    while (!qu.empty()) {
        int value = qu.front();
        qu.pop();

        // 두 배 값 처리
        if (value * 2 <= 100000 && dist[value * 2] == -1) {
            dist[value * 2] = dist[value] + 1; // 거리 업데이트
            qu.push(value * 2); // 큐에 추가
        }

        // +1 값 처리
        if (value + 1 <= 100000 && dist[value + 1] == -1) {
            dist[value + 1] = dist[value] + 1;
            qu.push(value + 1);
        }

        // -1 값 처리
        if (value - 1 >= 0 && dist[value - 1] == -1) {
            dist[value - 1] = dist[value] + 1;
            qu.push(value - 1);
        }
    }

    cout << dist[y] << endl; // 동생의 위치까지의 최단 시간 출력

    return 0;
}
