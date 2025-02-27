#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1},MAX =301;
int map[MAX][MAX], killed[MAX][MAX], N, M;
bool is_killed = false, visited[MAX][MAX] = {false} ;
pair<int,int> s,t;

void BFS(){
    memset(visited,false,sizeof(visited));

    queue<pair<int,int>> que;
    que.push(s);

    killed[s.first][s.second] = 0;
    killed[t.first][t.second] = 5;
    visited[s.first][s.second] = true;

    while(que.size()){
        auto [x,y] = que.front(); que.pop();
        if(map[x][y] == '#'){
            killed[x][y] = 7;
            is_killed = true; 
            return;
        }
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > M || visited[nx][ny]) continue;
            if(map[nx][ny] == '1' && killed[nx][ny] == 0){
                killed[nx][ny] = 1;   
                visited[nx][ny] = true;
                continue;
            }
            visited[nx][ny] = true;
            que.emplace(nx,ny);
        }
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(map,0,sizeof(map));
    memset(killed,0,sizeof(killed));

    cin >> N >> M;
    cin >> s.first >> s.second >> t.first >> t.second;
    cin.ignore();
    
    for(int i = 1; i <= N; ++i){
        string input;
        getline(cin,input);
        for(int j = 1; j <= M; ++j){
            map[i][j] = input[j-1];
        }
    }
    int cnt{0};
    while(1){
        ++cnt;
        BFS();
        if(is_killed) break;
    }    
    cout << cnt << "\n";
    return 0;
}