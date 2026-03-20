#include <iostream>

using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int N, M, db[502][502], dp[502][502];

int DFS(int y, int x){
    if( x == N-1 && y == M-1){ 
        return 1;
    }
    
    int& ret = dp[y][x]; 
    if(ret != -1) return ret;

    dp[y][x] = 0;

    for(int i{}; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(db[ny][nx] >= db[y][x]) continue;

        dp[y][x] += DFS(ny,nx);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;
    fill(&db[0][0],&db[0][0]+502*502,0);
    fill(&dp[0][0],&dp[0][0]+502*502,-1);

    for(int y{}; y < M; ++y){
        for(int x{}; x < N; ++x){
            cin >> db[y][x];
        }
    }
    DFS(0,0);
    cout << dp[0][0] << endl;

    return 0;
}