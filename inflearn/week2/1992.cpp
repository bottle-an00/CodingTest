#include <iostream>
#include <vector>
#include <string>
using namespace std;
using Map = vector<vector<int>>;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int DFS(Map map, int x = 0, int y = 0){
    bool visited[65][65];
    fill(&visited[0][0], &visited[0][0] + 65*65 , false);
    visited[x][y] = true;
    int cnt = 1;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= map[0].size() 
        || ny < 0 || ny >= map[0].size() 
        || visited[ny][nx]) 
        {
            continue;
        }
        cnt += DFS(map,nx,ny);
    }
    return cnt;
}
vector<Map> divideMap(int mask_size, int i, Map map){
    const pair<int,int> cycle[4] = {{0,0}, {1,0}, {0,1} ,{1,1}};
    vector<Map> submaps;
    for(int i = 0; i < 4; ++i){
        int sx = cycle->first*mask_size;
        int sy = cycle->second*mask_size;
        Map submap;
        submap.assign(mask_size,vector<int>(mask_size));
        for(int dx = 0; dx < mask_size; ++dx){
            for(int dy = 0; dy < mask_size; ++dy){
                submap[dy][dx] = map[sy+dy][sx+dx]; 
            }
        }
        submaps.push_back(submap);
    }
    return submaps;
}
string solve_1992(int mask_size, Map map){
    string result;
    if(mask_size == 1) return to_string(map[0][0]);
    if(DFS(map) == mask_size*mask_size) return to_string(map[0][0]);
}