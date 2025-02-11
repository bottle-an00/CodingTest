#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
void BFS(vector<vector<int>> map){
    int N = map.size(); int M = map[0].size();
    queue<pair<int,int>> que;
    vector<vector<int>> dist(N,vector<int>(M,0));
    que.push({0,0});
    dist[0][0] = 1;
    while(!que.empty()){
        pair<int,int> u = que.front();
        que.pop();
        for(int i=0; i < 4; ++i){
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] == 0 && map[nx][ny] == 1){
                que.push({nx,ny});
                dist[nx][ny] = dist[u.first][u.second] + 1;
            }
        }
    }
    cout << dist[N-1][M-1];
}

int main(){
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    cin.ignore();
    vector<vector<int>> map(N,vector<int>(M));
    for(int x = 0 ; x < N; ++x){
        string input;
        getline(cin,input);
        for(int y = 0; y <input.size(); ++y){
            map[x][y] = input[y]-'0';
        }
    }
    BFS(map);
    return 0;
}