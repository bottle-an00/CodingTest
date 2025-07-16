#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

int N{},M{},db[8][8],res{numeric_limits<int>::max()};
const pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int,int>> v;
vector<vector<int>> t={
                    {},
                    {0},
                    {0,2},
                    {0,1},
                    {0,1,2},
                    {0,1,2,3}
};

int count(int new_db[8][8]){
    int cnt{};
    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            if(new_db[r][c] == 0) cnt++;
        }
    }
    return cnt;
}

void go(int idx, int new_db[8][8]){
    if(idx == v.size()){
        res = min(res, count(new_db));
        return;
    }
    int tmp[8][8];
    memcpy(tmp,new_db,sizeof(int)*8*8);
    int type = db[v[idx].first][v[idx].second];
    for(int i{}; i < 4; ++i){
        for(auto e: t[type]){
            int nr = v[idx].first;   
            int nc = v[idx].second;
            while(1){
                nr += dir[(i+e)%4].first;
                nc += dir[(i+e)%4].second;
                if(nc < 0 || nr < 0 || nc >= M || nr >= N) break;
                if(tmp[nr][nc] == 6) break;
                tmp[nr][nc] = 7;
            }
        }
        go(idx + 1, tmp);
        memcpy(tmp, new_db, sizeof(int)*8*8);
    }
}

int main(){
    cin >> N >> M;

    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            cin >> db[r][c];
            if(db[r][c] > 0 && db[r][c] < 6) v.emplace_back(r,c);
        }
    }
    
    go(0,db);
    cout << res;
    return 0;
}