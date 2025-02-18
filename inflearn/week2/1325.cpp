#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
Graph G;
vector<bool> visited;
int DFS(int u){
    visited[u] = true;
    int ret {1};
    for(auto v : G[u]){
        if(visited[v]) continue;
        ret += DFS(v);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{}, M{};
    cin >> N >> M;
    G.resize(N);
    visited.resize(N,false);
    for(int m = 0; m < M; ++m){
        int a{},b{};
        cin >> a >> b;
        --a;--b;
        G[b].push_back(a);
    }
    vector<pair<int,int>> result;
    for(int i = 0; i < N; ++i){
        visited.assign(N,false);
        result.emplace_back(i,DFS(i));
    }
    sort(result.begin(),result.end(),[&](const pair<int,int> a, const pair<int,int> b){
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    int maximum = result[0].second;
    for(auto e : result){
        if(e.second == maximum) cout << ++e.first << " ";
    }
    return 0;
}