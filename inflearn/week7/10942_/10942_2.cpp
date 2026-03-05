#include <memory>
#include <iostream>
#include <cstring>

using namespace std;
int N, M, S, E;
int d[2004], dp[2004][2004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> d[i];
    }

    //logic start 
    //길이가 1개인 경우
    for(int i{1}; i <= N; ++i) dp[i][i] = 1;

    //길이가 2개인 경우
    for(int i{1}; i < N; ++i) dp[i][i+1] = (d[i] == d[i+1]) ? 1 : 0;

    //길이가 3인 경우 
    for(int len{3}; len <= N; ++len){
        for(int i{1} ; i+len - 1 <= N; ++i){
            dp[i][i+len-1] = (d[i] == d[i+len-1] && dp[i+1][i+len-2] == 1) ? 1 : 0;
        }
    }

    cin >> M;
    for(int i{}; i < M; ++i){
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}