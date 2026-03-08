#include <iostream>

using namespace std;
using ll = long long;

ll N{},K{},a[104],dp[10004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    fill(&dp[0], &dp[0] + 10004 , 0);
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }

    dp[0]=1;
    for(int i{}; i < N; ++i){
        for(int j{a[i]}; j <= K; ++j){
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[K];
    return 0;
}