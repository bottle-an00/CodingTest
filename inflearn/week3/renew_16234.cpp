#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int mask[54][54], map[54][54];
bool visited[54][54];
int N, R, L;

bool check_possible(pair<int, int> u, pair<int, int> n) {
    int diff = abs(map[n.first][n.second] - map[u.first][u.second]);
    return (diff >= L && diff <= R);
}

bool BFS_making_mask(int idx, pair<int, int> s) {
    queue<pair<int, int>> que;
    vector<pair<int, int>> union_countries;
    
    visited[s.first][s.second] = true;
    que.push(s);
    union_countries.push_back(s);

    while (!que.empty()) {
        auto [ux, uy] = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || !check_possible({ux, uy}, {nx, ny})) continue;
            visited[nx][ny] = true;
            que.emplace(nx, ny);
            union_countries.push_back({nx, ny});
        }
    }

    if (union_countries.size() > 1) {
        for (auto [x, y] : union_countries) mask[x][y] = idx;
        return true;
    }
    return false;
}

bool make_mask() {
    bool has_movement = false;
    fill(&mask[0][0], &mask[0][0] + 54 * 54, 0);
    fill(&visited[0][0], &visited[0][0] + 54 * 54, false);
    int idx{1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && BFS_making_mask(idx,{i, j})) {
                idx++;
                has_movement = true;
            }
        }
    }
    return has_movement;
}

void adjust_population(pair<int, int> s) {
    vector<int*> countries;
    int sum = 0, count = 1;
    visited[s.first][s.second] = true;
    countries.push_back(&map[s.first][s.second]);
    sum += map[s.first][s.second];
    queue<pair<int, int>> que;
    que.push(s);
    int union_num = mask[s.first][s.second];
    while (!que.empty()) {
        auto [ux, uy] = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || mask[nx][ny] != union_num) continue;
            visited[nx][ny] = true;
            que.emplace(nx, ny);
            count++;
            sum += map[nx][ny];
            countries.push_back(&map[nx][ny]);
        }
    }

    int population = sum / count;
    for (auto e : countries) {
        *e = population;
    }
}

void open_borders() {
    fill(&visited[0][0], &visited[0][0] + 54 * 54, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mask[i][j] && !visited[i][j]) adjust_population({i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    int days = 0;
    while (true) {
        if (!make_mask()) break;
        open_borders();
        days++;
    }
    cout << days << endl;
    return 0;
}
