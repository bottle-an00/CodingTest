#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int visited[2][MAX], N, K,t,max_t;
void solve_17071(int start) {
    queue<int> que;
    que.emplace(start);
    visited[0][N] = 1;
    t = 1;
    bool ok{false};
    while (que.size()) {
        int cur_sibling = K+(t*(t+1))/2;
        if(cur_sibling >= MAX) break;
        if(visited[t%2][cur_sibling]){
            ok =true;
            break;
        }
        int qSize = que.size();
        for(int i = 0; i < qSize; ++i){
            int c = que.front(); que.pop();
            for (int n : {c - 1, c + 1, c * 2}) {
                if (n < 0 || n >= MAX || visited[(t)%2][n]) continue;
                visited[(t)%2][n] = visited[(t+1)%2][n] + 1;
                if (n == cur_sibling) {
                    ok = true;
                    break;
                }
                que.emplace(n);
            }if(ok) break;
        }if(ok) break;
        ++t;
    }
    if(ok) cout << t << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> K;
    if(N == K) {cout << 0 <<"\n"; return 0;}
    memset(visited, 0, sizeof(visited));

    solve_17071(N);
    return 0;
}
