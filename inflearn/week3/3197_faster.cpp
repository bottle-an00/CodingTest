#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1501;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
int R,C;
char map[MAX][MAX];
bool water_visited[MAX][MAX], swan_visited[MAX][MAX];
queue<pair<int,int>> swan, next_swan, water, next_water;
void queue_clear(queue<pair<int,int>>& q){
    queue<pair<int,int>> empty_queue;
    swap(q,empty_queue);
}
void melting_ice(){
    while(water.size()){
        auto [x,y] = water.front(); water.pop();
        for(int j = 0; j <4; ++j){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || nx >=R || ny < 0 || ny >= C || water_visited[nx][ny])continue;
            if(map[nx][ny] == 'X'){
                map[nx][ny] = '.';
                water_visited[nx][ny] = true;
                next_water.emplace(nx,ny);
            }
        }
    }
}
bool BFS(){
    while(swan.size()){
        auto [x,y] = swan.front(); swan.pop();

        for(int j = 0; j < 4; ++j){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || nx >=R || ny < 0 || ny >= C||swan_visited[nx][ny])continue;
            swan_visited[nx][ny] = true;
            if(map[nx][ny] == 'L') return true;//이부분
            else if(map[nx][ny] == 'X'){
                next_swan.emplace(nx,ny);
            }
            else if(map[nx][ny] == '.'){
                swan.emplace(nx,ny);
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    memset(water_visited, false, sizeof(water_visited));
    memset(swan_visited, false, sizeof(swan_visited));

    cin >> R >> C;
    cin.ignore();
    for(int r = 0; r < R; ++r){
        string input;
        getline(cin, input);
        bool get_start_point{false};
        for(int c = 0; c < C; ++c){
            map[r][c] = input[c];
            if(map[r][c] != 'X') water.emplace(r,c);
            if(map[r][c] == 'L' && swan.size() == 0) {
                swan.emplace(r,c);
                swan_visited[r][c] = true;
            }
        }
    }
    int cnt{};
    while(true){
        if(BFS()){
            cout << cnt << "\n";
            return 0;
        }
        melting_ice();

        swan = next_swan;
        water = next_water;
        queue_clear(next_swan);
        queue_clear(next_water);
        ++cnt;
    }
    return 0;
}