#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int visited[2][MAX], N, K,t,max_t;
void solve_17071(int start) {
    queue<pair<int,int>> que;
    que.emplace(start,0);
    visited[0][N] = 0;
    while (!que.empty()) {
        auto [c,t] = que.front();
        int cur_sibling = K+(t*(t+1))/2;
        que.pop();
        if(cur_sibling >= MAX){
            cout << -1 << "\n";
            return;
        }
        if(visited[t%2][cur_sibling] != -1){
            cout << t << "\n";
            return;
        }
        int next[3] = {c - 1, c + 1, c * 2};
        for (int n : next) {
            if (n < 0 || n >= MAX) continue;
            if(visited[(t+1)%2][n] == -1){
                visited[(t+1)%2][n] = t + 1;
                que.emplace(n,t+1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> K;
    memset(visited, -1, sizeof(visited));

    solve_17071(N);
    return 0;
}
