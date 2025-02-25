#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int map[1004][1004],fire_dist[1004][1004],visited[1004][1004],R,C;
vector<pair<int,int>> fire_start_position;
void BFS(){
    queue<pair<int,int>> que;
    for(auto p : fire_start_position){
        fire_dist[p.first][p.second] = 0;
        que.push(p);
    }
    while(!que.empty()){
        auto [ux,uy] = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if(nx < 0 || nx >= R || ny < 0|| ny >= C) continue;
            if(map[nx][ny] == '#' || fire_dist[nx][ny] <= fire_dist[ux][uy] + 1) continue;
            fire_dist[nx][ny] = fire_dist[ux][uy] + 1;
            que.emplace(nx,ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    cin.ignore();
    pair<int, int> jihoon;
    
    for (int i = 0; i < R; ++i) {
        string input;
        getline(cin, input);
        for (int j = 0; j < C; ++j) {
            map[i][j] = input[j];
            if (map[i][j] == 'F') fire_start_position.push_back({i, j});
            if (map[i][j] == 'J') jihoon = {i, j};
        }
    }
    fill(&fire_dist[0][0],&fire_dist[0][0]+1004*1004,__INT_MAX__);
    fill(&visited[0][0],&visited[0][0]+1004*1004,-1);
    BFS();
    int dist = -1;
    queue<pair<int,int>> que;
    que.push(jihoon);
    visited[jihoon.first][jihoon.second] = 0;
    while(!que.empty()){
        auto [x,y] = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i]; int ny = y + dy[i]; 
            if(nx < 0 || nx == R || ny < 0 || ny == C) {
                cout << visited[x][y] +1<< "\n";
                return 0;
            }
            if(visited[nx][ny] != -1|| map[nx][ny] == '#') continue;
            if(visited[x][y] + 1 >= fire_dist[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            que.emplace(nx,ny);
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}