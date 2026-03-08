#include <iostream>

using namespace std;
int N{}, a[16][16], dp[16][16][3];

const int dr[3] = {0,1,1};
const int dc[3] = {1,0,1};

int go(int r, int c, int mode){
    if(r == N-1 && c == N-1) return 1;

    int &ret = dp[r][c][mode];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 3; ++i){
        if ((mode == 0 && i == 1) || (mode == 1 && i == 0)) continue;
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= N || nc >= N || a[nr][nc]) continue;
        if(i == 2 && (a[r][nc] || a[nr][c])) continue;
        ret += go(nr, nc, i);
    }
    return ret;
}

int main(){
    cin >> N;
    fill(&dp[0][0][0], &dp[0][0][0] + 16*16*3 , -1);
    for(int i{}; i < N; ++i){
        for(int j{}; j < N; ++j){
            cin >> a[i][j];
        }
    }
    cout << go(0,1,0);
    return 0;
}