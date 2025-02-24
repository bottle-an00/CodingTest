#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int mask[54][54], map[54][54];
bool visited[54][54];
int N{},R{},L{};
bool check_possible(pair<int,int> u, pair<int,int> n){
    int diff = abs(map[n.first][n.second] - map[u.first][u.second]);
    if(diff >= L && diff <= R) return true;
    else return false; 
}
int BFS_making_mask(pair<int,int> s){
    visited[s.first][s.second] = true;
    queue<pair<int,int>> que;
    que.push(s);
    int count{};
    while(!que.empty()){
        auto [ux,uy] = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny >= N) continue;
            if(visited[nx][ny] || !check_possible({ux,uy},{nx,ny})) continue;
            mask[ux][uy] = 1;
            mask[nx][ny] = 1;
            visited[nx][ny] = true;
            que.emplace(nx,ny);
            count++;
        }
    }
    return count;
}
bool make_mask(){
    fill(&mask[0][0],&mask[0][0]+54*54,0);
    int n_connected_component{};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(mask[i][j] == 0){
                n_connected_component += BFS_making_mask({i,j});
            }
        }
    }
    return n_connected_component;
}
void adjust_population(pair<int,int> s){
    vector<int*> countries;
    int sum{},count{1};
    visited[s.first][s.second] = true;
    countries.push_back(&map[s.first][s.second]);
    sum += map[s.first][s.second];
    queue<pair<int,int>> que;
    que.push(s);
    while(!que.empty()){
        auto [ux,uy] = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny >= N) continue;
            if(visited[nx][ny] || !mask[nx][ny]) continue;
            visited[nx][ny] = true;
            que.emplace(nx,ny);
            count++;
            sum += map[nx][ny];
            countries.push_back(&map[nx][ny]);
        }
    }
    int populations = sum / count;
    for(auto e : countries){
        *e = populations;
    }
}
void open_borders(){
    fill(&visited[0][0],&visited[0][0]+54*54,false);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(mask[i][j] == 1) adjust_population({i,j});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> L >> R;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> map[i][j]; 
        }
    }
    int count_down = 2000;
    while(count_down){
        if(make_mask()) {
            open_borders();
            count_down--;
        }
        else break;
    }
    cout << 2000 - count_down << endl;
    return 0;
}