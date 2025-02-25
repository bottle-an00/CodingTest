#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int max_ = 1000001;
int dist[max_],par[max_], N, K,result{INT_MAX};
vector<int> traj;
void get_trajectory(){
    traj.clear();
    int child = K;
    while(1){
        if(child == -1 ) break;
        traj.push_back(child);
        child = par[child];
    }
}
void solve_12581(int current){
    queue<pair<int,int>> que;
    que.emplace(current,0);
    dist[current] = 0;
    while(que.size()){
        auto [c,t] = que.front();
        que.pop();
        if (c == K){
            if(result > t){
                result = t;
                get_trajectory();
            }
            continue;
        }
        int next[3]={c-1, c+1,c*2};
        for(int n : next){
            if(n < 0 || n >1000000) continue;
            if(dist[n] == -1 || dist[n] == t + 1){
                dist[n] = t +1;
                que.emplace(n,t+1);
                par[n] = c;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    fill(&dist[0],&dist[0]+max_,-1);
    fill(&par[0],&par[0]+max_,-1);
    solve_12581(N);
    cout << result << "\n";
    for(int i = traj.size()-1; i >=0; --i){
        cout << traj[i] <<" ";
    }
    return 0;
}