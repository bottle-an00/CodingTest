#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1},MAX =301;
int map[MAX][MAX], N, M;
bool visited[MAX][MAX] = {false} ;
pair<int,int> s,t;

void BFS(){
    int cnt {1};
    queue<pair<int,int>> que;
    queue<pair<int,int>> que_kill;
    que.push(s);

    visited[s.first][s.second] = true;

    while(que.size()){
        auto [x,y] = que.front(); que.pop();
        if(map[x][y] == '#') {cout  << cnt << "\n"; return;}
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > M || visited[nx][ny]) continue;
            if(map[nx][ny] == '1'){
                que_kill.emplace(nx,ny);
                visited[nx][ny] = true;
                continue;
            }
            visited[nx][ny] = true;
            que.emplace(nx,ny);
        }
        if(que.size() == 0){
            ++cnt;
            swap(que,que_kill);
        }
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(map,0,sizeof(map));
    memset(visited,false,sizeof(visited));

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
    BFS();
    return 0;
}