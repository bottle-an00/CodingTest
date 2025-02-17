#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Map = vector<vector<int>>;
using Point = pair<int,int>;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
void BFS(const Map& map, Map& visited){
    int N = map.size(); int M = map[0].size();
    queue<Point> que;
    que.emplace(0,0);
    visited[0][0] = 1;
    while(!que.empty()){
        auto [x,y] = que.front(); 
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(map[nx][ny] != 0 || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            que.emplace(nx,ny);
        }
    }
}
bool is_marginal(Point p, const Map& map, const Map& visited){
    int N = map.size(); int M = map[0].size();

    for(int i = 0; i < 4; ++i){
        int nx = p.first + dx[i], ny = p.second + dy[i];
        if(map[nx][ny] == 0 && visited[nx][ny] == 1) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N{}, M{};
    cin >> N >> M;
    Map map(N,vector<int>(M,0));
    vector<Point> cheese;
    for(int n = 0; n < N; ++n){
        for(int m = 0; m < M; ++m){
            cin >> map[n][m];
            if(map[n][m] == 1) cheese.emplace_back(n,m);
        }
    }

    int last_cheese{}, count{};
    while(!cheese.empty()){
        Map visited(N, vector<int>(M, 0));
        BFS(map,visited);
        vector<Point> not_melted_cheese;
        for(auto& e : cheese){
            if(is_marginal(e, map,visited)) 
                map[e.first][e.second] = 0;
            else 
                not_melted_cheese.push_back(e);
        }
        last_cheese = cheese.size();
        cheese = move(not_melted_cheese);
        ++count;
    }
    cout << count << "\n" << last_cheese;
    return 0;
}