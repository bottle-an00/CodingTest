#include <iostream>
#include <queue>

using namespace std;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int N, M, cnt, db[302][302], visited[302][302];

void BFS(int y, int x){
    queue<pair<int,int>> que;
    que.emplace(y,x);
    visited[y][x] = 1;

    while(!que.empty()){
        auto [y,x] = que.front(); que.pop();

        for(int i{}; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ny < 0 || ny >= N || nx < 0|| nx >=M) continue;
            if(visited[ny][nx]) continue;
            if(db[ny][nx] == 0) continue;

            visited[ny][nx] = 1;
            que.emplace(ny,nx);
        }
    }
}

int is_divide(){
    int ice_cnt{};

    fill(&visited[0][0], &visited[0][0]+302*302, 0);

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            if(db[y][x] > 0 && !visited[y][x]){
                BFS(y,x);
                ice_cnt++;
            }
        }
    }
    return ice_cnt;
}

void melt(){
    int tmp[302][302] = {0};

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            if(db[y][x] > 0){
                int water = 0;

                for(int i{}; i < 4; ++i){
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny < 0 || ny >= N || nx < 0|| nx >=M) continue;
                    if(db[ny][nx] == 0) water++;
                }

                tmp[y][x] = max(0, db[y][x] - water);
            }
        }
    }

    // 복사
    for(int y{}; y < N; ++y)
        for(int x{}; x < M; ++x)
            db[y][x] = tmp[y][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int y{}; y < N; ++y){
        for(int x{}; x < M; ++x){
            cin >> db[y][x];
        }
    }

    while(true){
        int div = is_divide();

        if(div >= 2){
            cout << cnt << endl;
            break;
        }

        if(div == 0){
            cout << 0 << endl;
            break;
        }

        melt();
        cnt++;
    }

    return 0;
}