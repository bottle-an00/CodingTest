#include <iostream>

using namespace std;
using ii = pair<int,int>;

int N{},K{},dp[100002];
ii a[102];

int main(){
    cin >> N >> K;
    for(int i{}; i < N; ++i){
        cin >> a[i].first >> a[i].second;
    }
    fill(&dp[0],&dp[0]+100002,0);
    for(int i{}; i < N; ++i){
        for(int k{K}; k >= a[i].first; --k){
            dp[k] = max(dp[k], dp[k - a[i].first] + a[i].second);
        }
    }
    cout << dp[K];
    return 0;
}