#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N{},M{},K{};
bool visited[104][104];
int map[104][104];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
vector<int> result;
int DFS(int x, int y)
{
    int ret = 1;
    visited[y][x] = true;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i]; int ny = y +dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[ny][nx] == true) continue;
        if(map[ny][nx] == 1) continue;
        ret += DFS(nx,ny);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> M >> N >> K;
    fill(&map[0][0],&map[0][0] + 104*104 ,0);
    fill(&visited[0][0],&visited[0][0] + 104*104 ,false);
    for(int k = 0; k < K; ++k){
        int lx{},ly{},rx{},ry{};
        cin >> lx >> ly >> rx >> ry;
        for(int x = lx; x < rx; ++x){
            for(int y = ly; y < ry; ++y){
                map[y][x] = 1;
            }
        }
    }
    for(int x = 0; x < N; ++x){
        for(int y = 0; y < M; ++y){
            if(!visited[y][x] && map[y][x] == 0){
                result.push_back(DFS(x,y));
            }
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << endl;    
    for(auto e : result){
        cout << e <<" ";
    }
    return 0;
}