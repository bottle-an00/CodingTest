#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
bool visited[51] = {false};
int N{}, r{}, cnt{};
void DFS(Graph G, int u){
    visited[u] = true;
    if(u == r) return;
    if(G[u].size() == 0){
        ++cnt;
        return;
    }
    for(auto v : G[u]){
        if(v == r){
            if(G[u].size() == 1) ++cnt;
            else continue;
        }
        if(visited[v]) continue;
        DFS(G,v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    int root{};
    Graph G(N);
    for(int n = 0; n < N; ++n){
        int par{};
        cin >> par;
        if(par == -1) root = n;
        else
            G[par].push_back(n);
    }
    cin >> r;
    DFS(G, root);
    cout << cnt;
    return 0;
}