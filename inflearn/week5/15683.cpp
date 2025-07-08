#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

int N{},M{},db[8][8],res{numeric_limits<int>::max()};
const pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int,int>> v;


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
    if(idx >= v.size()-1){
        res = min(res, count(new_db));
    }

    for(int i{}; i < 4; ++i){
        int nr = v[idx].first;   
        int nc = v[idx].second;
        while(1){
            nr += dir[i].first;
            nc += dir[i].second;
            if(nc < 0 || nr < 0 || nc >= M || nr >= N) break;
            new_db[nr][nc] = 7;
        }   
        go(idx +1, new_db);
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
    cout << v.size() << endl;
    int new_db[8][8];
    memcpy(new_db,db,sizeof(db));
    go(0,new_db);

    return 0;
}