#include <iostream>
#include <vector>
#include <string>
using namespace std;
using Map = vector<vector<int>>;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
bool visited[65][65] = {false};
int DFS(Map map, int x = 0, int y = 0){    
    visited[y][x] = true;
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
        if(map[ny][nx] == map[y][x]){
            cnt += DFS(map,nx,ny);
        }
    }
    return cnt;
}
vector<Map> divideMap(int mask_size, Map map){
    const pair<int,int> cycle[4] = {{0,0}, {0,1}, {1,0} ,{1,1}};
    vector<Map> submaps;
    for(int i = 0; i < 4; ++i){
        int sx = cycle[i].first*mask_size;
        int sy = cycle[i].second*mask_size;
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
    result += '(';
    if(mask_size == 1) return to_string(map[0][0]);
    fill(&visited[0][0], &visited[0][0] + 65*65 , false);
    if(DFS(map) == mask_size*mask_size) {
        return to_string(map[0][0]);
    }
    vector<Map> submaps = divideMap(mask_size/2,map);
    for(int i = 0; i < 4; ++i){
        result += solve_1992(mask_size/2,submaps[i]);
    }
    result += ')';

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    cin.ignore();
    Map map;
    map.assign(N,vector<int>(N,0));
    for(int i = 0; i <N; ++i){
        string input;
        getline(cin,input);
        for(int j = 0; j < input.size(); ++j){
            map[j][i] = input[j] - '0';
        }
    } 
    cout << solve_1992(N,map) << endl;
    return 0;
}