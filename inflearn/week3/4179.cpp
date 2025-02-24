#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int visited[2][1004][1004], map[1004][1004], R, C, cnt;

int BFS(pair<int, int> s, vector<pair<int, int>> f_s) {
    visited[1][s.first][s.second] = 1;
    queue<pair<int, int>> que, f_que;
    que.push(s);
    
    for (auto fire : f_s) {
        visited[0][fire.first][fire.second] = 1;
        f_que.push(fire);
    }
    
    while (!que.empty()) {
        int f_size = f_que.size();
        while (f_size--) {
            auto [fx, fy] = f_que.front(); f_que.pop();
            for (int i = 0; i < 4; ++i) {
                int f_nx = fx + dx[i];
                int f_ny = fy + dy[i];
                if (f_nx < 0 || f_nx >= R || f_ny < 0 || f_ny >= C) continue;
                if (visited[0][f_nx][f_ny] || map[f_nx][f_ny] == '#') continue;
                map[f_nx][f_ny] = 'F';
                visited[0][f_nx][f_ny] = 1;
                f_que.emplace(f_nx, f_ny);
            }
        }
        
        int q_size = que.size();
        while (q_size--) {
            auto [x, y] = que.front(); que.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) return cnt + 1;
                if (visited[1][nx][ny] || map[nx][ny] != '.') continue;
                visited[1][nx][ny] = 1;
                que.emplace(nx, ny);
            }
        }
        ++cnt;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    cin.ignore();
    vector<pair<int, int>> f_s;
    pair<int, int> s;
    
    for (int i = 0; i < R; ++i) {
        string input;
        getline(cin, input);
        for (int j = 0; j < C; ++j) {
            map[i][j] = input[j];
            if (map[i][j] == 'F') f_s.push_back({i, j});
            if (map[i][j] == 'J') s = {i, j};
        }
    }
    
    int result = BFS(s, f_s);
    if (result == -1) cout << "IMPOSSIBLE\n";
    else cout << result << "\n";
    return 0;
}
