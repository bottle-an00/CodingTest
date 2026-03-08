#include <iostream>

#define W 0
#define H 1

using ll = long long;
using namespace std;

int N{};
ll dp[60][2][30];

ll dfs(int day, int status, int cnt){
    if((2*N - 2*cnt  - day < 0) && status == H) return 0;
    if(cnt < 0 && status == W) return 0;
    if(day == 2*N) return 1;

    ll &res = dp[day][status][cnt];
    if( res != -1) return res;

    res = dfs(day+1, W,cnt-1) + dfs(day+1,H,cnt);
    return res;
}

int main(){
    while(1){
        cin >> N;
        if(N == 0) break;
        fill(&dp[0][0][0], &dp[0][0][0]+60*2*30, -1);
        cout << dfs(1,W,N-1) <<"\n";
    }
    return 0;
}