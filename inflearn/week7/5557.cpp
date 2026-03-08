#include <iostream>
#include <queue>

using namespace std;
int N, a[104], dp[104][21];
queue<pair<int,int>> que;

void BFS(int idx, int sum){
    que.push({idx,sum});
    
    while(!que.empty()){
        auto [idx, sum] = que.front();
        que.pop();
        if(idx == N-1 && sum == a[N-1]){
            dp[N-1][sum] = (dp[N-1][sum] + 1) % 1000000000; 
            continue;
        }

        if(idx + 1 < N){
            int ret = sum + a[idx+1];
            if(ret <= 20){
                que.push({idx+1,ret});
                dp[idx+1][ret] = (dp[idx+1][ret] + 1) % 1000000000;
            }
            ret = sum - a[idx+1];
            if(ret >= 0){
                que.push({idx+1,ret});
                dp[idx+1][ret] = (dp[idx+1][ret] + 1) % 1000000000;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }

    dp[0][0] = 1;
    BFS(0,a[0]);
    cout << dp[N-1][a[N-1]] % 1000000000 << '\n';
    return 0;
}