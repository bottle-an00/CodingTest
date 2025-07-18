#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int dist[1000004], N, K,result{-1},cnt;
void solve_12581(int current){
    queue<pair<int,int>> que;
    que.emplace(current,0);
    dist[current] = 0;
    while(que.size()){
        auto [c,t] = que.front();
        que.pop();
        if (c == K){
            if (result == -1){
                result = t;
                cnt = 1;
            }
            else if(result == t){
                ++cnt;
            }
            continue;
        }
        int next[3]={c-1, c+1,c*2};
        for(int n : next){
            if(n < 0 || n >1000000) continue;
            if(dist[n] == -1 || dist[n] == t + 1){
                dist[n] = t +1;
                que.emplace(n,t+1);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    fill(&dist[0],&dist[0]+1000004,-1);
    solve_12581(N);
    cout << result << "\n";
    cout << cnt << "\n";
    return 0;
}