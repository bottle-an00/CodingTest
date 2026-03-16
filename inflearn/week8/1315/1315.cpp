#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Quest {
    int str, intel, pnt;
};

int N, dp[1001][1001];
vector<Quest> quests;
bool visited[51];

int solve(int s, int i) {
    int& ret = dp[s][i];
    if (ret != -1) return ret;

    int total_pnt = 0;
    int cnt = 0;
    vector<int> can_clear;

    for (int idx = 0; idx < N; idx++) {
        if (quests[idx].str <= s || quests[idx].intel <= i) {
            total_pnt += quests[idx].pnt;
            cnt++;
            if (!visited[idx]) {
                visited[idx] = true;
                can_clear.push_back(idx);
            }
        }
    }

    ret = cnt;

    int remain_pnt = total_pnt - (s - 1 + i - 1);

    for (int p = 0; p <= remain_pnt; p++) {
        int next_s = min(1000, s + p);
        int next_i = min(1000, i + (remain_pnt - p));

        if (next_s != s || next_i != i) {
            ret = max(ret, solve(next_s, next_i));
        }
    }

    for (int idx : can_clear) {
        visited[idx] = false;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, it, p;
        cin >> s >> it >> p;
        quests.push_back({s, it, p});
    }

    cout << solve(1, 1) << endl;

    return 0;
}