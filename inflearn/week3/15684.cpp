#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> G;
int N, M, H, rst = INT_MAX;

bool go() {
    for (int i = 1; i <= N; ++i) {
        int result = i;
        for (int j = 1; j <= H; ++j) {
            if (result < N && G[j][result] == 1) result++;
            else if (result > 1 && G[j][result - 1] == 1) result--;
        }
        if (result != i) return false;
    }
    return true;
}

void change(int cnt, int start_x, int start_y) {
    if (cnt > 3 || cnt >= rst) return; 
    if (go()) {
        rst = min(rst, cnt);
        return;
    }
    for (int j = start_y; j <= H; ++j) {
        for (int i = (j == start_y ? start_x : 1); i < N; ++i) {
            if (G[j][i] == 1 || G[j][i + 1] == 1) continue;
            G[j][i] = 1;
            change(cnt + 1, i, j);
            G[j][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;
    G.assign(H + 1, vector<int>(N + 1, 0));

    for (int m = 0; m < M; ++m) {
        int j, i;
        cin >> j >> i;
        G[j][i] = 1;
    }

    change(0, 1, 1);
    cout << (rst == INT_MAX ? -1 : rst) << "\n";
    return 0;
}
