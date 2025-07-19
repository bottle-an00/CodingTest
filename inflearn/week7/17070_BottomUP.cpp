#include <iostream>

using namespace std;

int N{},a[16][16],dp[16][16][3];

bool check(int nr, int nc, int ns){
    if(nr >= N || nc >= N) return false;

    if(ns == 0 || ns == 1){ 
        if(a[nr][nc] == 0) return true;
    }
    else{
        if(a[nr][nc] == 0 && a[nr-1][nc] == 0 && a[nr][nc-1] == 0) return true;
    }
    return false;
}

int main(){
    cin >> N;
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            cin >> a[r][c];
        }
    }
    fill(&dp[0][0][0],&dp[0][0][0] + 16*16*3,0);
    dp[0][1][0] = 1;

    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            //현재 direction이 0인 것에 대한 다음 step
            if(check(r,c+1,0)) dp[r][c+1][0] += dp[r][c][0];
            if(check(r+1,c+1,2)) dp[r+1][c+1][2] += dp[r][c][0];

            //현재 direction이 1인 것에 대한 다음 step
            if(check(r+1,c,1)) dp[r+1][c][1] += dp[r][c][1];
            if(check(r+1,c+1,2)) dp[r+1][c+1][2] += dp[r][c][1];

            //현재 direction이 2인 것에 대한 다음 step
            if(check(r,c+1,0)) dp[r][c+1][0] += dp[r][c][2];
            if(check(r+1,c,1)) dp[r+1][c][1] += dp[r][c][2];
            if(check(r+1,c+1,2)) dp[r+1][c+1][2] += dp[r][c][2];
        }
    }
    cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2];
    return 0;
}