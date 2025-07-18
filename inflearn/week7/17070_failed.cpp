#include <iostream>

using namespace std;
int N{}, a[16][16], dp[16][16][3];

const int dr[3] = {0,1,1};
const int dc[3] = {1,0,1};

void go(int cr, int cc, int mod){
    if(cr == N-1 && cc == N-1) return;

    for(int i{}; i < 3; ++i){
        if ((mod == 0 && i == 1) || (mod == 1 && i == 0)) continue;
        
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        if((nr >= N || nc >= N ) || a[nr][nc]) continue;
        if(i == 2 && (a[cr][nc] || a[nr][cc])) continue;
        dp[nr][nc][i] += dp[cr][cc][mod];
        go(nr,nc,i);
    }

    return;
}

int main(){
    cin >> N;
    fill(&dp[0][0][0], &dp[0][0][0] + 16*16*3 , 0);
    for(int i{}; i < N; ++i){
        for(int j{}; j < N; ++j){
            cin >> a[i][j];
        }
    }

    dp[0][1][0] = 1;
    go(0,1,0);
    cout << dp[N-1][N-1][0] << " "<< dp[N-1][N-1][1] <<" " <<  dp[N-1][N-1][2] << endl; 
    int res = dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2]; 
    cout << res;
    return 0;
} 