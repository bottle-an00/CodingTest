#include <iostream>

using namespace std;
const int INF = 1e9;
int N{},K{},a[104],dp[10004];

int dfs(int k){
    if(k == K) return 0;
    if(k > K) return INF;

    int &res = dp[k];
    if(res != -1) return res;

    res = INF;
    for(int i{}; i < N; ++i){
        res = min(res,dfs(k + a[i])+1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }
    fill(&dp[0],&dp[0]+10004,-1);
    int ans = dfs(0);
    cout << (ans == INF ? -1 : ans);
    return 0;
}