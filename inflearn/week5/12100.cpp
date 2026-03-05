#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        queue<int> q;
        for(int c{}; c < N; ++c){
            if(tdb[r][c] > 0) q.push(tdb[r][c]);
            tdb[r][c] = 0;
        }
        int s{};
        vector<int> result;
        if(q.size()) {
            s = q.front();q.pop();
            if(q.empty()) result.push_back(s);
        }

        while(q.size()){
            int t = q.front();q.pop();
            if(s == t){
                s *= 2;
                result.push_back(s);
                if(q.size()) {s = q.front();q.pop();}
            }else{
                result.push_back(s);
                s = t;
                if(q.empty()) result.push_back(s);
            }
        }

        int l{N-1};
        while(result.size()){
            tdb[r][l] = result.back();
            result.pop_back();
            res = max(res,tdb[r][l]);
            l--;
        }
    }
        show_db(tdb);

}

void go(int cnt, vector<vector<int>> tdb){
    if(cnt == 5) return;
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