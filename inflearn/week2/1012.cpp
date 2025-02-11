#include <iostream>
#include <queue>
#include <string>
using namespace std;

int cnt = 2;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
vector<vector<int>> map;
int N,M,T;
void BFS(int x, int y){
    queue<pair<int,int>> que;
    que.emplace(x,y);
    map[x][y] = cnt;
    while(!que.empty()){
        pair<int,int> u = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = u.first + dx[i];
            int ny = u.second +dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] != 1) continue;
            else{//map[nx][ny] ==1 인경우 + 범위 내에 포함
                map[nx][ny] = cnt;
                que.emplace(nx,ny);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_case;
    cin >> num_case;
    for(int n =0; n < num_case; ++n){
        cin >> N >> M >> T;
        cnt = 2;
        map.assign(N,vector<int>(M,0));
        for(int i =0  ; i < T; ++i){
            int x,y;
            cin >> x >> y;
            map[x][y] =1;   
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j< M; ++j){
                if(map[i][j] == 1){
                    BFS(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt - 2 << endl;
    } 
    return 0;
}