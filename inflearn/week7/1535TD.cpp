#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, L[22], J[22];
int dp[21][101]; 
const int INF = 1e9;

int dfs(int idx, int hp){
    if(hp <= 0) return -INF; 
    if(idx == N) return 0;   

    int &res = dp[idx][hp];
    if(res != -1) return res;

    res = dfs(idx + 1, hp);

    if(hp - L[idx] > 0){
        res = max(res, dfs(idx + 1, hp - L[idx]) + J[idx]);
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i) cin >> L[i];
    for(int i = 0; i < N; ++i) cin >> J[i];

    memset(dp, -1, sizeof(dp));
    int ret = dfs(0, 100);
    cout << ret << '\n';
}
