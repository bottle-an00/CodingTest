#include <iostream>
#include <vector>

using namespace std;

int N,M,cnt{}, max_area[2] ={0,0}, dataDB[52][52];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
vector<int> visited;
vector<int> areaDB;

void DFS(int x, int y){
    for(int i{}; i <4; ++i){
        int vx = x + dx[i];
        int vy = y + dy[i];

        if(vx < 0 || vx >= N || vy < 0 || vy >=M) continue;
        if(visited[vy*N+vx]) continue;
        if(dataDB[y][x] & (1 << i))continue;
        visited[vy*N+vx] = cnt;
        DFS(vx,vy);
    }
}

void check_area(){
    for(int r{}; r < M; ++r){
        for(int c{}; c < N; ++c){
            if (visited[r*N + c] == 0) continue;
            areaDB[visited[r*N+c]]++;
        }
    }
    for(auto e : areaDB){
        max_area[0] = max(max_area[0], e);
    }
}

void break_wall(){
    for(int r{}; r < M; ++r){
        for(int c{}; c < N; ++c){
            for(int i = 0; i < 4; ++i){
                int vx = c + dx[i];
                int vy = r + dy[i];
                
                if(vx < 0 || vx >= N || vy < 0 || vy >=M) continue;
                if(dataDB[r][c] & (1 << i)){
                    if(visited[vy*N+vx] != visited[r*N+c]){
                        max_area[1] = max(max_area[1],areaDB[visited[vy*N+vx]] + areaDB[visited[r*N+c]]);
                    }
                } 
            }
        }
    }
}

int main(){
    cin >> N >> M;
    
    fill(&dataDB[0][0] , &dataDB[0][0] + 52*52,0);//-> 이부분에서 52가 아닌 54를 사용하는 경우 runtime 에러가 발생한다. 
    for(int r{}; r < M; ++r){
        for(int c{}; c < N; ++c){
            cin >> dataDB[r][c];
        }
    }

    visited.assign(N*M, 0);

    for(int y{}; y < M; ++y){
        for(int x{}; x < N; ++x){
            if(visited[y*N+x]) continue;
            cnt++;
            visited[y*N+x]= cnt;
            DFS(x,y);
        }
    }

    areaDB.assign(cnt+1,0);

    check_area();
    break_wall();
    cout << cnt << endl << max_area[0] << endl << max_area[1]<< endl;
    return 0;
}