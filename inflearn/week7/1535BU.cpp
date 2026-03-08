#include <iostream>

using namespace std;
int N{},L[22],J[22],dp[102];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i{}; i < N; ++i) cin >> L[i];
    for(int i{}; i < N; ++i) cin >> J[i];
    for(int i{}; i < N; ++i){
        for(int s{100}; s > L[i]; --s){
            dp[s] = max(dp[s], dp[s - L[i]] + J[i]);
        }
    }
    cout << dp[100];
    return 0;
}