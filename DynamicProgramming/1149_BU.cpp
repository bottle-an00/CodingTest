#include <iostream>

using namespace std;
int dp[1004][3], N, db[1004][3];
const int INF = 1e9;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    fill(&dp[0][0], &dp[0][0]+1004*3, INF);
    fill(&db[0][0], &db[0][0] + 1004*3, 0); 
    
    for(int i{}; i < N; ++i){
        for(int c{}; c < 3; ++c){
            cin >> db[i][c];
        }
    }

    for(int idx{}; idx < N; ++idx){
        for(int c{}; c < 3; ++c){
            if(idx == 0) dp[idx][c] = db[idx][c];
            
            dp[idx][c] = db[idx][c] + min(dp[idx-1][(c+1)%3], dp[idx-1][(c+2)%3]);
        }
    }

    int ans = min(dp[N-1][0], dp[N-1][1]);
    ans = min(ans, dp[N-1][2]);
    cout << ans<< "\n";
    return 0;
}