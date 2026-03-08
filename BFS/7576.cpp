#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ii = pair<int,int>;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int N, M, db[1002][1002], dist[1002][1002], ans;
vector<ii> rotten_tmt;
queue<ii> que;

void BFS(){
    while(!que.empty()){
        ii loc = que.front(); que.pop();

        for(int i{}; i < 4; ++i){
            int nx = loc.second + dx[i];
            int ny = loc.first + dy[i];

            if(nx < 0 | nx >= M | ny < 0 | ny >= N) continue;
            if(dist[ny][nx] != -1) continue;
            if(db[ny][nx] == -1) continue;

            que.emplace(ny,nx);
            dist[ny][nx] = dist[loc.first][loc.second] + 1;
        }
    }
}

int check(){
    int max_v = -1;

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            //모든 토마토가 익을 수 없는 경우
            if(db[y][x] != -1 && dist[y][x] == -1) return -1;

            //토마토가 익을 수 있는 경우
            if(db[y][x] != -1){
                max_v = max(max_v, dist[y][x]);
            }
        }
    }

    return max_v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill(&db[0][0], &db[0][0] + 1002*1002, -1);
    fill(&dist[0][0], &dist[0][0] + 1002*1002, -1);

    cin >> M >> N;

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            cin >> db[y][x];
            if( db[y][x] == 1) rotten_tmt.emplace_back(y,x);
        }
    }

    for(auto e : rotten_tmt){
        que.emplace(e);
        dist[e.first][e.second] = 0;
    }

    BFS();

    //check
    ans = check();
    cout << ans << "\n";

    return 0;
}