#include <iostream>

using namespace std;

const int INF = 1e9;
int N{},dp[1000004],next_X[1000004];

int dfs(int X){
    if( X == 1) return 0;
    if( X < 1) return INF;

    int &res = dp[X];
    if(res != -1) return res;

    res = INF;
    if(X % 3 == 0){
        int next = dfs(X/3);
        if(res > next){
            res = next + 1;
            next_X[X] = X/3;
        }
    }
    if(X % 2 ==0){
        int next = dfs(X/2);
        if(res > next){
            res = next + 1;
            next_X[X] = X/2;
        }
    }
    if(X > 1){
        int next = dfs(X-1);
        if(res > next){
            res = next + 1;
            next_X[X] = X-1;
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> N;
    fill(&dp[0], &dp[0]+1000004,-1);
    cout << dfs(N) << "\n";
    int idx = N;
    while(1){
        cout << idx << " ";
        if(idx == 1) break;
        idx = next_X[idx];
    }
    return 0;
}