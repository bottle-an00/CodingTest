#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N, a[104]; 
long long dp[104][21];


int main(){

    memset(dp, 0, sizeof(dp));;

    cin >> N;
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }

    dp[0][a[0]] = 1;
    for(int i{}; i < N-1; ++i){
        for(int j{}; j <=20; ++j){
            if(dp[i][j] == 0) continue;

            if(j + a[i+1] <= 20) dp[i+1][j + a[i+1]] += dp[i][j];
            if(j - a[i+1] >=  0) dp[i+1][j - a[i+1]] += dp[i][j];
        }
    }

    cout << dp[N-2][a[N-1]] << "\n";

    return 0;
}