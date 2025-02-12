#include <iostream>
#include <vector>
#include <string>
using namespace std;
using Map = vector<vector<int>>;
const pair<int,int> cycle[4] = {{0,0},{0,1},{1,0},{1,1}};
Map map;
string solve_1992(int x, int y, int mask_size,Map map){
    if(mask_size == 1) return to_string(map[y][x]);
    string result;
    for(int dy = y; dy < y + mask_size; ++dy){
        for(int dx = x; dx < x + mask_size; ++dx){
            if(map[dy][dx] != map[y][x]){
                result += '(';
                for(int i = 0; i < 4; ++i){
                    result += solve_1992(x + cycle[i].first*mask_size/2, y + cycle[i].second*mask_size/2, mask_size/2,map);
                }
                result += ')';
                return result;
            }
        }
    }
    result += to_string(map[y][x]);
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
    cout << solve_1992(0,0,N,map) << endl;
    return 0;
}