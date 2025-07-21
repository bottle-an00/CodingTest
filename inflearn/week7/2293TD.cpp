#include <iostream>

using namespace std;
using ll = long long;

ll N{},K{},a[104],dp[104][10004];

ll dfs(int k, int idx){
    if(k == K) return 1;
    if(k > K) return 0;

    ll &res = dp[k][idx];
    if(res != -1) return res;

    res = 0;
    for(int i{idx}; i < N; ++i){
        res += dfs(k + a[i],i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    fill(&dp[0][0], &dp[0][0] + 10004*104 , -1);
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }

    cout << dfs(0,0);
    return 0;
}