#include <iostream>
#include <algorithm>

using namespace std;

int a[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int res = 1e9;

bool canAttach(int r, int c, int size) {
    if (r + size > 10 || c + size > 10) return false;
    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

void attach(int r, int c, int size, int val) {
    for (int i = r; i < r + size; ++i)
        for (int j = c; j < c + size; ++j)
            a[i][j] = val;
}

void dfs(int r, int c, int cnt) {
    if (r == 10) {
        res = min(res, cnt);
        return;
    }

    if (c == 10) {
        dfs(r + 1, 0, cnt);
        return;
    }

    if (a[r][c] == 0) {
        dfs(r, c + 1, cnt);
        return;
    }

    for (int size = 5; size >= 1; --size) {
        if (paper[size] == 0) continue;
        if (canAttach(r, c, size)) {
            attach(r, c, size, 0);
            paper[size]--;
            dfs(r, c + 1, cnt + 1);
            attach(r, c, size, 1); 
            paper[size]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int r = 0; r < 10; ++r)
        for (int c = 0; c < 10; ++c)
            cin >> a[r][c];

    dfs(0, 0, 0);
    cout << (res == 1e9 ? -1 : res) << '\n';
    return 0;
}
