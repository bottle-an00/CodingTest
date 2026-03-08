#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;
using iii = tuple<int, int, int>;

const int dr[4] = {0, 0, -1, 1};
const int dc[4] = {1, -1, 0, 0};

int N, K;
int board[13][13];
vector<int> db[13][13];
vector<iii> info;

bool in_range(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < N;
}

int simulate() {
    for (int turn = 1; turn <= 1000; ++turn) {
        for (int k = 0; k < K; ++k) {
            auto& [r, c, d] = info[k];
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (!in_range(nr, nc) || board[nr][nc] == BLUE) {
                d ^= 1;
                nr = r + dr[d];
                nc = c + dc[d];

                if (!in_range(nr, nc) || board[nr][nc] == BLUE) {
                    continue; 
                }
            }

            auto& cur = db[r][c];
            auto it = find(cur.begin(), cur.end(), k);
            vector<int> moving(it, cur.end());
            cur.erase(it, cur.end());

            if (board[nr][nc] == RED) {
                reverse(moving.begin(), moving.end());
            }

            for (int id : moving) {
                info[id] = {nr, nc, get<2>(info[id])};
                db[nr][nc].push_back(id);
            }

            if ((int)db[nr][nc].size() >= 4) return turn;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            cin >> board[r][c];

    info.resize(K);
    for (int k = 0; k < K; ++k) {
        int r, c, d;
        cin >> r >> c >> d;
        --r; --c; --d;
        info[k] = {r, c, d};
        db[r][c].push_back(k);
    }

    cout << simulate();
    return 0;
}
