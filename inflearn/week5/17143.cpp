#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct shark{
    int r{},c{},s{},d{},z{};
    bool dead{true};
};

const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,1,-1};

int R{},C{},M{},num_shark{},king{},z_sum{};
int shark_id[104][104];
int nshark_id[104][104];
vector<shark> db;

void move_king(){
    for(int r{}; r < R; ++r){
        int id = shark_id[r][king];

        if(id && !db[id].dead){
            z_sum += db[id].z;
            db[id].dead = true;
            shark_id[r][king] =0;
            num_shark--;
            return;
        }
    }
}

void move_shark(){
    fill(&nshark_id[0][0], &nshark_id[0][0]+104*104 ,0);

    for(int idx{1}; idx <= M; ++idx){
        if(db[idx].dead) continue;

        int r = db[idx].r;
        int c = db[idx].c;
        int s = db[idx].s;
        int d = db[idx].d;

        int nr{},nc{};
        while(1){
                nr = r + s*dr[d]; 
                nc = c + s*dc[d];
            if(nr >=0 && nc >= 0 && nr < R && nc < C) break;
            if(d <= 1){// 0~R
                if(nr < 0){
                    s -= r;
                    r = 0;
                }else{
                    s -= (R-1) - r;
                    r = R-1;
                }
            }else{
                if(nc < 0){
                    s -= c;
                    c = 0;
                }else{
                    s -= (C-1) - c;
                    c = C - 1;
                }
            }
            d ^= 1;

        }
        int id = nshark_id[nr][nc];
        if(id){
            if(db[id].z < db[idx].z){
                nshark_id[nr][nc] = idx;
                db[id].dead = true;
                num_shark--;
            }else{
                db[idx].dead = true;
            }
        }else{
            nshark_id[nr][nc] = idx;
        }
        db[idx].r = nr; db[idx].c = nc; db[idx].d = d;
    }
    memcpy(shark_id,nshark_id,sizeof(shark_id));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C >> M;

    num_shark = M;
    fill(&shark_id[0][0], &shark_id[0][0]+104*104 ,0);
    db.assign(M+1,shark());

    for(int m{1}; m <= M; ++m){
        cin >> db[m].r >> db[m].c >> db[m].s >> db[m].d >> db[m].z;
        db[m].r--; db[m].c--; db[m].d--;
        db[m].dead = false;
        if(db[m].d <= 1) db[m].s %= (2*(R-1));
        else db[m].s %= (2*(C-1));
        shark_id[db[m].r][db[m].c] = m;
    }

    while(num_shark != 0 && king < C){
        move_king();
        move_shark();

        king++;
    }

    cout << z_sum;
    return 0;
}