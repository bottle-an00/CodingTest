#include <iostream>

using namespace std;

int N, db[1004][3], dp[1004][3];
const int INT_MAX = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    fill(&db[0][0], &db[0][0]+1004*3, 0);
    fill(&dp[0][0], &dp[0][0]+1004*3, INT_MAX);

    for(int i{}; i < N; ++i){
        for(int c{}; c < 3; ++c){
            cin >> db[i][c];
        }
    }

    for(int i{}; i < N; ++i){
        for(int c{}; c < 3; ++c){
            if(i == 0) dp[i][c] = db[i][c];
            else dp[i][c] = db[i][c] + min(dp[i-1][(c+1)%3], dp[i-1][(c+2)%3]);
        }
    }

    int ans = min(dp[N-1][0],dp[N-1][1]);
    ans = min(ans, dp[N-1][2]);

    cout << ans << "\n";
    return 0;
}