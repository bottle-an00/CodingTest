#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using Graph = vector<vector<int>>;

int N{},min_diff(INT_MAX);
vector<int> population,status;
//status {0, 1}
/*
    0 : not visited
    1 : visited
*/

Graph G;

void BFS(int start, int mask){
    queue<int> q;
    q.push(start);
    status[start] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        
        for(auto v : G[u]){
            if(status[v]) continue;

           if (((mask >> u) & 1) == ((mask >> v) & 1)){
                status[v] = 1;
                q.push(v);
            }
        }

    }

}

void solve_17471(){
    for(int mask{1}; mask < (1 << N)-1; mask++){
        bool is_possible = true;
        vector<vector<int>> group(2);

        //divide group
        for(int i{}; i < N; i++){
            if(mask & (1 << i)) group[1].push_back(i);
            else group[0].push_back(i);
        }

        //check possible
        status.assign(N,0);
        BFS(group[0][0], mask);
        BFS(group[1][0], mask);
        for(int i{}; i < N; i++){
            if(status[i] == 0) {
                is_possible = false;
                break;
            }
        }
        if(!is_possible) continue;

        //find min diff
        int sum0{},sum1{};
        for(auto e : group[0]){
            sum0 += population[e];
        }
        for(auto e : group[1]){
            sum1 += population[e];
        }

        int diff = abs(sum0 - sum1);

        min_diff = min(diff, min_diff);
    }

    if(min_diff == INT_MAX) cout << -1 << endl;
    else cout << min_diff << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    G.assign(N,vector<int>());
    population.assign(N,0);

    for(int i{}; i < N; i++){
        cin >> population[i];
    }

    for(int i{}; i < N; i++){
        int n{};
        cin >> n;
        for(int j{}; j < n; j++){
            int node;
            cin >> node;
            G[i].push_back(node-1);
            G[node-1].push_back(i);
        }
    }
    solve_17471();
    return 0;
}