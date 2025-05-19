#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

int T{},N{},M{},visited[1004];
Graph G;

void DFS(int from,int& cnt){
    visited[from] = 1;
    for(auto to : G[from]){
        
        if(visited[to]) continue;
        cnt++;
        DFS(to,cnt);
    }
}

bool solve_13244(){
    int cnt = 1;
    DFS(1, cnt);
    if(cnt == N ){
        if(M == N - 1) return true;
    } 

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int t{}; t < T; ++t){
        cin >> N;
        G.assign(N+1,vector<int>());
        fill(&visited[0],&visited[0] + 1004, 0);
        
        cin >> M;
        for(int m{}; m < M; ++m){
            int a{},b{};
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cout << (solve_13244() ? "tree" : "graph") << endl;
    }

    return 0;
}