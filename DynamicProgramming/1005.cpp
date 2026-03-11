#include <iostream>
#include <vector>

using namespace std;

int T,N,K,W,db[1001], dp[1001];
vector<vector<int>> graph;

int dfs(int dst){

    int& res = dp[dst];
    if(res != -1) return res;

    int max_t = 0;

    for(int i = 0; i < graph[dst].size(); ++i){
        int next = graph[dst][i];
        max_t = max(max_t, dfs(next));
    }

    return res = max_t + db[dst];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    while(T--){

        cin >> N >> K;

        graph.assign(N+1, vector<int>());
        fill(dp, dp+1001, -1);

        for(int i = 1; i <= N; i++)
            cin >> db[i];

        for(int i = 0; i < K; i++){
            int from, to;
            cin >> from >> to;
            graph[to].push_back(from);
        }

        cin >> W;

        cout << dfs(W) << "\n";
    }


    return 0;
}