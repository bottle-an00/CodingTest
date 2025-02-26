#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int sum[MAX],visited[MAX], N, K,t,max_t;
bool is_over = false;
int get_distance(){
    sum[0] = K;
    int t =1;
    while(1){
        if(sum[t-1] >= MAX -1) break;
        sum[t] = sum[t-1] + t;
        ++t;
    }
    max_t = t -2;
    return max_t;
}
void solve_17071(int start) {
    queue<pair<int,int>> que;
    que.emplace(start,0);

    while (!que.empty()) {
        auto [c,t] = que.front();
        que.pop();
        if(c >= MAX -1){
            is_over = true;
            continue;
        }
        for(int i = t; i < max_t; ++i){
            if(c == sum[i]) {
                is_over = false;
                cout << i << "\n";
                return;
            }
        }
        
        int next[3] = {c - 1, c + 1, c * 2};
        for (int n : next) {
            if (n < 0 || n >= MAX || visited[n]) continue;
            que.emplace(n,t+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> K;
    memset(sum, 0, sizeof(sum));
    memset(visited, 0, sizeof(visited));

    solve_17071(N);
    if(is_over) cout << -1 << "\n";
    return 0;
}
