#include <iostream>
#include <vector>
using namespace std;

int visited[54][54], map[54][54], N, L, R, sum, cnt;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
vector<pair<int,int>> v;
void dfs(int x, int y, vector<pair<int,int>>& v){
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N||visited[nx][ny])continue;
        int diff = abs(map[nx][ny] - map[x][y]);
        if(diff <= R && diff >= L) {
            visited[nx][ny] = true;
            v.emplace_back(nx,ny);
            sum += map[nx][ny];
            dfs(nx,ny,v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> L >> R;
    for(int i = 0; i < N;++i){
        for(int j = 0 ; j < N; ++j){
            cin >> map[i][j];
        }
    }
    while(true){
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54*54,false);

        for(int i = 0; i < N;++i){
            for(int j = 0 ; j < N; ++j){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = true;
                    v.emplace_back(i,j);
                    sum = map[i][j];
                    dfs(i,j,v);
                    if(v.size() == 1) continue;
                    for(auto b : v){
                        map[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }

        if(!flag) break;
        cnt ++;
    }
    cout << cnt << endl;
    return 0;
}