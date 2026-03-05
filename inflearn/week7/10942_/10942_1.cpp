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

    //logic start => 잘못됨
    for(int i{1}; i <= N; ++i){
        for(int j{i}; j <= N; ++j){
            // 1개인 경우
            if(i == j) dp[i][j] = 1;
            // 2개인 경우
            else if(j - i == 1) dp[i][j]  = (d[i] == d[j]) ? 1 : 0;
            // 나머지
            else{
                dp[i][j] = (d[i] == d[j] && dp[i + 1][j - 1] == 1) ? 1 : 0;
            }
        }
    }

    cin >> M;
    for(int i{}; i < M; ++i){
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}