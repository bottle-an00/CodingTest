#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N{},M{};
const int dx[4] = {-1,0,1,0};
const int dy[4] = { 0, -1, 0, 1};
int visited[54][54];
char map [54][54];
vector<pair<int,int>> land;

int BFS(pair<int,int> s){
    int result{};
    visited[s.first][s.second] = 0;
    queue<pair<int,int>> que;
    que.push(s);
    while(!que.empty()){
        auto [ux,uy] = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] != -1 || map[nx][ny] == 'W') continue;
            visited[nx][ny] = visited[ux][uy] + 1;
            result = visited[nx][ny];
            que.emplace(nx,ny);
        }
    }
    return result;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    cin.ignore();
    for(int i = 0; i < N; ++i){
        string input;
        getline(cin,input);
        for(int j = 0; j < M; ++j){
            map[i][j] = input[j];
            if(map[i][j] == 'L') land.emplace_back(i,j);
        }
    }
    int result{};
    for(int i = 0; i < land.size(); ++i){
        fill(&visited[0][0],&visited[0][0]+54*54,-1);
        result = max(result, BFS(land[i]));
    }
    cout << result << endl;
    return 0;
}