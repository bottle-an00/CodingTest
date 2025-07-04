#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const pair<int,int> dir[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int N{},res{};
vector<vector<int>> db;
void show_db(vector<vector<int>> tdb){
     cout << endl;
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            cout << tdb[r][c] << " ";
        }
        cout << endl;
    }
     cout << endl;
}
vector<vector<int>> preprocessing(int i, vector<vector<int>>& tdb){//i : db, o : ndb
    int flag{};
    int dir_r = dir[i].first;
    int dir_c = dir[i].second;

    if(dir_r + dir_c < 0) flag = 1;
    dir_r = abs(dir_r);
    dir_c = abs(dir_c);

    vector<vector<int>> rdb(N,vector<int>(N,0)); 
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            rdb[r*dir_c + c*dir_r][r*dir_r + c*dir_c] = tdb[r][c];
        }
    }
    if(flag) for(int r{}; r < N; ++r) reverse(rdb[r].begin(),rdb[r].end());
    return rdb;
}

void main_logic(vector<vector<int>>& tdb){//i: ndb
    for(int r{}; r < N; ++r){
        int lp{N-2},rp{N-1};
        while(lp >= 0){
            if(tdb[r][rp] == 0) {
                tdb[r][rp] = tdb[r][lp];
                tdb[r][lp] = 0;
                rp = lp;
                lp--;
            }else if(tdb[r][rp] == tdb[r][lp]){
                tdb[r][rp] *= 2;
                tdb[r][lp] = 0;
                rp = lp;
                lp--;
            }else{
                lp--; rp--;
            }
            res = max(res, tdb[r][rp]);
        }
        show_db(tdb);
    }
}

void go(int cnt, vector<vector<int>> tdb){
    if(cnt == 1) return;
    for(int i{0}; i < 4; ++i){
        vector<vector<int>> ndb = preprocessing(i,tdb);
        
        main_logic(ndb);

        go(cnt+1,ndb);
    }
    
}

int main(){
    cin >> N;
    db.assign(N,vector<int>(N,0));

    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            cin >> db[r][c];
            res = max(res, db[r][c]);
        }
    }
    go(0,db);
    cout << res;
    return 0;
}