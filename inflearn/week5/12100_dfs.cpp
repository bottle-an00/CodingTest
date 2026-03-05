#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res = 0;

vector<vector<int>> rotate(vector<vector<int>> board) {
    vector<vector<int>> ret(N, vector<int>(N));
    for(int r = 0; r < N; ++r)
        for(int c = 0; c < N; ++c)
            ret[c][N - 1 - r] = board[r][c];
    return ret;
}

vector<int> merge(vector<int> row) {
    vector<int> new_row;
    int prev = 0;

    for (int x : row) {
        if (x == 0) continue;
        if (x == prev) {
            new_row.back() *= 2;
            prev = 0;
        } else {
            new_row.push_back(x);
            prev = x;
        }
    }

    while (new_row.size() < N)
        new_row.push_back(0);

    return new_row;
}

vector<vector<int>> move_left(vector<vector<int>> board) {
    for (int i = 0; i < N; ++i) {
        board[i] = merge(board[i]);
    }
    return board;
}

void dfs(int depth, vector<vector<int>> board) {
    if (depth == 5) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                res = max(res, board[i][j]);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> next = move_left(board);
        dfs(depth + 1, next);
        board = rotate(board); 
    }
}

int main() {
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            cin >> board[r][c];

    dfs(0, board);
    cout << res;
    return 0;
}
