#include <iostream>
#include <vector>

using namespace std;

int V, visited[100002],far_node, ans;
vector<vector<pair<int,int>>> graph;

void dfs(int node, int dist){
    visited[node] = 1;

    if(dist > ans){
        ans = dist;
        far_node = node;
    }

    for(auto [next, w] : graph[node]){
        if(!visited[next]){
            dfs(next, dist + w);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V;
    graph.assign(V+1, vector<pair<int,int>>());

    for(int i = 0; i < V; ++i){
        int from;
        cin >> from;

        while(true){
            int to;
            cin >> to;

            if(to == -1) break;

            int w;
            cin >> w;

            graph[from].push_back({to, w});
        }
    }

    dfs(1, 0);

    fill(visited, visited + V + 1, 0);
    ans = 0;

    dfs(far_node, 0);

    cout << ans;

    return 0;
}