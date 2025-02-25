#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int dist[MAX], par[MAX], N, K;
vector<int> traj;

void get_trajectory() {
    traj.clear();
    for (int child = K; child != -1; child = par[child]) {
        traj.push_back(child);
    }
    reverse(traj.begin(), traj.end());
}

void solve_12581(int start) {
    queue<int> que;
    que.push(start);
    dist[start] = 0;

    while (!que.empty()) {
        int c = que.front();
        que.pop();

        if (c == K) {
            get_trajectory();
            return; 
        }

        int next[] = {c - 1, c + 1, c * 2};
        for (int n : next) {
            if (n < 0 || n >= MAX) continue;
            if (dist[n] == -1) { 
                dist[n] = dist[c] + 1;
                par[n] = c;
                que.push(n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    memset(dist, -1, sizeof(dist));
    memset(par, -1, sizeof(par));

    solve_12581(N);
    
    cout << dist[K] << "\n";
    for (int x : traj) {
        cout << x << " ";
    }
    return 0;
}
