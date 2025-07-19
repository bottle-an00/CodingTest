#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
char board[50][50];
int dp[50][50];
bool visited[50][50];
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

int dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M || board[r][c] == 'H') return 0;
    if (visited[r][c]) return -1;  
    if (dp[r][c]) return dp[r][c];

    visited[r][c] = true;
    int max_moves = 0;
    int move = board[r][c] - '0';

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i] * move;
        int nc = c + dc[i] * move;
        int result = dfs(nr, nc);
        if (result == -1) return -1;
        max_moves = max(max_moves, result);
    }

    visited[r][c] = false;
    return dp[r][c] = max_moves + 1;
}

int main() {
    cin >> N >> M;
    cin.ignore();
    for (int r = 0; r < N; ++r) {
        string s;
        getline(cin, s);
        for (int c = 0; c < M; ++c) {
            board[r][c] = s[c];
        }
    }

    int res = dfs(0, 0);
    cout << res;
    return 0;
}
