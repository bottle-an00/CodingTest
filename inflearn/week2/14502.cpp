#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using PointXY = std::pair<int,int>;
using Map = vector<vector<int>>;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };
int BFS(PointXY s, Map map, Map wall){
    queue<PointXY> que;
    que.push(s);
    int count{};
    while(!que.empty()){
        PointXY u = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = u.first + dx[i]; 
            int ny = u.second + dy[i]; 
            if(nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size() || map[nx][ny]) continue;
            if(map[nx][ny] == 0 && wall[nx][ny] == 0){
                map[nx][ny] = 2;
                ++count;
                que.emplace(nx,ny);
            }
        }
    }
    return count;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{}, M{};
    cin >> N >> M;
    Map map(N,vector<int>(M,0));
    vector<PointXY> virus_positions;
    vector<PointXY> vacant_positions;
    for(int n = 0; n < N; ++n){
        for(int m = 0; m < M; ++m){
            cin >> map[n][m];
            if(map[n][m] == 2) virus_positions.emplace_back(n,m);
            if(map[n][m] == 0) vacant_positions.emplace_back(n,m);
        }
    }
    int result = N*M;
    size_t size = vacant_positions.size();
    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size; ++j){
            for(int k = j + 1; k < size; ++k){
                Map wall(N,vector<int>(M,0));
                wall[vacant_positions[i].first][vacant_positions[i].second] = 1; 
                wall[vacant_positions[j].first][vacant_positions[j].second] = 1; 
                wall[vacant_positions[k].first][vacant_positions[k].second] = 1;
                for(int t = 0; t < virus_positions.size(); ++t){
                    result = min(result, BFS(virus_positions[t],map,wall));
                } 
            }
        }
    }
    // cout << vacant_positions.size() - result;
    cout << result;
    return 0;
}