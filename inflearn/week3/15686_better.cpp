#include <iostream>
#include <vector>
using namespace std;

int N, M, ret = __INT_MAX__;
vector<pair<int, int>> house, chicken;
vector<int> selected; 

int cal_chicken_distance() {
    int sum = 0;
    for (const auto& h : house) {
        int dist = __INT_MAX__;
        for (int idx : selected) {
            auto& c = chicken[idx];
            dist = min(dist, abs(h.first - c.first) + abs(h.second - c.second));
        }
        sum += dist;
    }
    return sum;
}

void solve_15686(int idx, int count) {
    if (count == M) {
        ret = min(ret, cal_chicken_distance());
        return;
    }
    for (int i = idx; i < chicken.size(); ++i) {
        selected.push_back(i);
        solve_15686(i + 1, count + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int input;
            cin >> input;
            if (input == 1) house.emplace_back(i, j);
            if (input == 2) chicken.emplace_back(i, j);
        }
    }

    solve_15686(0, 0);
    cout << ret << '\n';
    return 0;
}
