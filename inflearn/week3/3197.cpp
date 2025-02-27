#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1},MAX =1501;
bool visited[MAX][MAX] = {false};
int map[MAX][MAX], R, C, cnt{0};
bool flag = false ;
bool is_water[MAX][MAX] = {false};
pair<int,int> s;

void melting_ice(int u, int v){
    queue<pair<int,int>> que;
    que.push({u,v});
    is_water[u][v] = true;

    while(que.size()){
        auto [x,y] = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C || is_water[nx][ny]) continue;
            if(map[nx][ny] == 'X'){
                map[nx][ny] = '.';
                is_water[nx][ny] = true;
                continue;
            }
            is_water[nx][ny] = true;
            que.emplace(nx,ny);
        }
    }
} 

void BFS(){
    queue<pair<int,int>> que;
    que.push(s);
    fill(&visited[0][0],&visited[0][0]+MAX*MAX,false);
    visited[s.first][s.second] = true;

    while(que.size()){
        auto [x,y] = que.front(); que.pop();
        if(map[x][y] == 'L' ) { flag = true; cout  << cnt << "\n"; return;}
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
            if(map[nx][ny] == 'X' || visited[nx][ny] ) continue;
            visited[nx][ny] = true;
            que.emplace(nx,ny);
        }
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(map,0,sizeof(map));

    cin >> R >> C;
    cin.ignore();
    bool set_start{true};
    for(int i = 0; i < R; ++i){
        string input;
        getline(cin,input);
        for(int j = 0; j < C; ++j){
            map[i][j] = input[j];
            if(map[i][j] == 'L' && set_start) {
                s = {i,j}; 
                map[i][j] = 'S';
                set_start = false;
            }
        }
    }
   
    while(1){
        BFS();
        if(flag) break;
        memset(is_water,false,sizeof(is_water));
        for(int r = 0; r < R; ++r){
            for(int c = 0; c< C; ++c){
                if(map[r][c] == '.' && !is_water[r][c]) melting_ice(r,c);
                
            }
        }
        ++cnt;
    }
    return 0;
}