#include <iostream>
#include <cstring>

using namespace std;
int N{}, M{}, s{}, e{}, a[2004], dp[2004][2004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    
    for(int i{1}; i <= N; ++i) dp[i][i] = 1;
    for(int i{1}; i < N; ++i) dp[i][i+1] = (a[i] == a[i+1]) ? 1 : 0;
    for(int len{2}; len <= N; ++len){
        for(int i{1}; i + len <= N; ++ i){
            int j = i + len;
            dp[i][j] = (a[i] == a[j] && dp[i+1][j-1] == 1) ? 1: 0;
        }
    }

    cin >> M;
    for(int i{}; i < M; ++i){
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}