#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using PointXY = pair<int, int>;
using Map = vector<vector<int>>;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int spreadVirus(const Map& map, const vector<PointXY>& virus_positions, const Map& wall) {
    int N = map.size(), M = map[0].size();
    Map infected = wall;  // 벽 정보 복사
    queue<PointXY> q;

    for (const auto& v : virus_positions) {
        q.push(v);
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == 0 && infected[nx][ny] == 0) {
                infected[nx][ny] = 2;  // 감염 처리
                q.push({nx, ny});
            }
        }
    }

    // 안전 영역 계산
    int safe_zone = 0;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            if (map[n][m] == 0 && infected[n][m] == 0) {
                ++safe_zone;
            }
        }
    }
    return safe_zone;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    Map map(N, vector<int>(M, 0));
    vector<PointXY> virus_positions, vacant_positions;

    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> map[n][m];
            if (map[n][m] == 2) virus_positions.emplace_back(n, m);
            if (map[n][m] == 0) vacant_positions.emplace_back(n, m);
        }
    }

    int max_safe_area = 0;
    int size = vacant_positions.size();

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                Map wall = map;
                wall[vacant_positions[i].first][vacant_positions[i].second] = 1;
                wall[vacant_positions[j].first][vacant_positions[j].second] = 1;
                wall[vacant_positions[k].first][vacant_positions[k].second] = 1;

                int safe_zone = spreadVirus(map, virus_positions, wall);
                max_safe_area = max(max_safe_area, safe_zone);
            }
        }
    }

    cout << max_safe_area << '\n';
    return 0;
}
