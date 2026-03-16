#include <memory>
#include <iostream>
#include <cstring>

using namespace std;
int N, M, S, E;
int d[2004], dp[2004][2004];

int go(int s, int e){
    if(s < S && e > E) return dp[s+1][e-1];

    if(s+1 < e-1 && dp[s+1][e-1] == 0) dp[s][e] = 0;

    else{//dp[s][e] == 1 or -1
        if(d[s] == d[e]){
            dp[s][e] = 1;
        }
        else dp[s][e] = 0;
    }
    return go(s-1, e+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> d[i];
    }

    cin >> M;
    for(int i{}; i < M; ++i){
        cin >> S >> E;
        int mid = (S + E) / 2;
        //홀수라면? 다음 step
        if((E - S) % 2 == 1) go (mid, mid + 1);
        else {
            dp[mid][mid] = 1;
            go(mid-1,mid+1);
        }
        cout << dp[S][E] << '\n';

    }

    return 0;
}