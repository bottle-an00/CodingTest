#include <iostream>

using namespace std;

int N, db[1004][3], dp[1004][3];
const int INT_MAX = 1e9;

int go(int idx, int color){
    if(idx == 0) return dp[idx][color] = db[idx][color];

    int& ret = dp[idx][color];
    if(ret != INT_MAX) return ret;

    return dp[idx][color] = db[idx][color] + min(go(idx -1, (color+1)%3), go(idx-1, (color+2)%3));
}

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

    int ans = min(go(N-1,0),go(N-1,1));
    ans = min(go(N-1,2), ans);
    cout << ans << "\n";

    return 0;
}