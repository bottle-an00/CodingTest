#include <iostream>
#include <queue>

using namespace std;
using ii = pair<int,int>;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int N, M, des1[102][102], des2[102][102], db[102][102], ans;

bool is_there_cheese(){
    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            if(db[y][x]) return true;
        }
    }
    return false;
}

void bfs(){
    queue<ii> que;
    que.emplace(0,0);
    des1[0][0] = 1;

    while(!que.empty()){
        ii prev = que.front(); que.pop();
        for(int i{}; i < 4; ++i){
            int ny = prev.first + dy[i];
            int nx = prev.second + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(des2[ny][nx]) continue;
            if(db[ny][nx]){//cheese

                if(des1[ny][nx]) des2[ny][nx] = 1;
                else des1[ny][nx] = 1;

            }else{//not cheese
                if(des1[ny][nx]) continue;
                des1[ny][nx] = 1;
                que.emplace(ny,nx);
            }
        }

    }
}

void remove_cheese(){
    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            if(des2[y][x]) db[y][x] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    fill(&db[0][0],&db[0][0]+102*102,0);

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            cin >> db[y][x];
        }
    }

    while(is_there_cheese()){
        //초기화
        fill(&des1[0][0],&des1[0][0]+102*102,0);
        fill(&des2[0][0],&des2[0][0]+102*102,0);
        bfs();

        remove_cheese();
        ans++;
    }
    cout << ans <<"\n";

    return 0;
}