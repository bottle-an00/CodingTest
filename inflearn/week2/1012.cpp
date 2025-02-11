#include <iostream>
#include <queue>
#include <string>
using namespace std;

int count = 1;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int map[104][104];
int N,M;
void BFS(){
    queue<pair<int,int>> que;
    que.emplace(0,0);
    while(!que.empty()){
        pair<int,int> u = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = u.first + dx[i];
            int ny = u.second +dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] != 1) continue;
            else{//map[nx][ny] ==1 인경우 + 범위 내에 포함
                ++count;
                map[nx][ny] = count;
                que.emplace(nx,ny);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    cin >> N >> M;
    cin.ignore();
    for(int x = 0; x < N; ++x){
        string input;
        getline(cin,input);
        for(int y = 0; y < M; ++y){
            map[x][y] = input[y];
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j< M; ++j){
            BFS();
        }
    }
    cout << count - 1 <<endl; 
    return 0;
}