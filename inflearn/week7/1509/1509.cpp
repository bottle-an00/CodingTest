#include <iostream>
#include <limits>
#include <string>
#include <cstring>

using namespace std;
string s;
int a[2504], dp[2504][2504], cut[2504];

int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    int N = s.size();
    for(int i{}; i < N; ++i){
        a[i] = s[i];
    }

    memset(dp, 0, sizeof(dp));
    for(int i{}; i < N; ++i) dp[i][i] = 1;
    for(int i{}; i < N-1; ++i) dp[i][i+1] = (a[i] == a[i+1]) ? 1 :0;
    for(int len{2}; len <= N; ++len){
        for(int i{}; i + len < N; ++i){
            int j = i + len;
            dp[i][j] = (a[i] == a[j] && dp[i+1][j-1]==1) ? 1: 0;
        }
    }

    for(int i{}; i < N; ++i) cut[i] = 1e9;

    for(int i{}; i < N; ++i){
        for(int j{0}; j <= i; ++j){
            if(dp[j][i] == 1){
                if(j == 0) cut[i] = 1;
                else cut[i] = min(cut[i], cut[j-1] + 1);
            }
        }
    }

    cout << cut[N-1] << '\n';
    return 0;
}