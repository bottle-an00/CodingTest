#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
int N, M, H, cnt{0};
bool go(){
    for(int i = 1; i <= N; ++i){//세로선 모두 탐색
        int result = i;
        for(int j = 1; j <= H; ++j){// 경로 지점 마다 가로선 존재 여부 확인
            if(G[i+j*N].size() > 0) {
                result = G[i+j*N][0];
            }
        }
        if(result != i) return false; 
    }
    return true;
}
bool change(int cnt){
    if(go()) {
        cout << cnt << endl;
        return true;
    }
    if(cnt == 3 ) return false;
    for(int i = 1; i <= N - 1; ++i){
        for(int j = 1; j <= H; ++j){
            if(G[i+j*N].size() > 0 || G[i+1+j*N].size() > 0) continue;
            G[i+j*N].push_back(i+1);
            G[i+1+j*N].push_back(i);
            change(cnt+1);
            G[i+j*N].pop_back();
            G[i+1+j*N].pop_back();
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M >> H;
    G.assign((N+2)*(M+2), vector<int>());
    for(int m = 1; m <= M; ++m){
        int i, j;
        cin >> j  >> i; 
        G[i + j*N].push_back(i+1);
        G[i + 1 + j*N].push_back(i);
    }
    if(!change(0)) cout << -1 << "\n";
    return 0;
}