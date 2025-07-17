#include <iostream>
#include <limits>
#include <cstring>

using namespace std; 
const int INF = 1e9;
int N{},dp[16][1 << 16], W[16][16];

int go(int cur, int visited){
    if(visited == (1 << N) -1) return W[cur][0] ? W[cur][0] : INF;

    int &res = dp[cur][visited];
    if( res != -1) return res;

    res = INF;
    for(int n{}; n < N; ++n){
        if(visited & (1<<n)) continue;
        if(W[cur][n] == 0) continue;
        res = min(res, go(n,visited | (1 << n)) + W[cur][n]);
    }
    return res;
}

int main(){
    cin >> N;
    for(int i{}; i < N; ++i){
        for(int j{}; j < N; ++j){
            cin >> W[i][j]; 
        }
    }
    fill(&dp[0][0],&dp[0][0]+16*(1 << 16),-1);
    cout << go(0,1);
    return 0;
}