#include <iostream>
#include <cstring>

using namespace std;

const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};

int R{},C{},T{},res{},db[104][104],Adb[104][104];
int ur{-1},lr{-1};

void step1(){

    for(int r{}; r < R; ++r){
        for(int c{}; c < C; ++c){
            int cnt{};
            if(db[r][c] > 0){
                for(int i{}; i < 4; ++i){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < 0 || nc < 0 || nc >= C || nr >= R) continue;
                    if(nr == ur && nc == 0 || nr == lr && nc == 0) continue;

                    Adb[nr][nc] += db[r][c]/5;
                    cnt++;
                }
                Adb[r][c] += db[r][c] - db[r][c] / 5 * cnt;
            }
        }
    }
    memcpy(db,Adb,sizeof(Adb));
    fill(&Adb[0][0],&Adb[0][0] + 104*104, 0);
}

void step2(int dir[4], int sr){
    int cc{0}, cr{sr}, next{db[cr][cc]};

    for(int i{}; i < 4; ++i){
        while(1){
            int nr = cr + dr[dir[i]];
            int nc = cc + dc[dir[i]];
            if(nr < 0 || nc < 0 || nr >= R || nc >= C) break;
            if(nr ==sr && nc == 0) break;

            int tmp = db[nr][nc];
            db[nr][nc] = next;
            next = tmp;

            cr = nr;
            cc = nc;
        } 
    }
}

void cal_res(){
    for(int r{}; r < R; ++r){
        for(int c{}; c < C; ++c){
            res += db[r][c];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C >> T;
    fill(&db[0][0],&db[0][0] + 104*104, 0);
    fill(&Adb[0][0],&Adb[0][0] + 104*104, 0);
    for(int r{}; r < R; ++r){
        for(int c{}; c < C; ++c){
            cin >> db[r][c];
            if(db[r][c] == -1) {
                if(lr < 0) {ur = r; lr = r+1;}
                db[r][c] = 0;
            }
        }
    }

    for(int t{}; t< T; ++t){
        step1();
        int u_dir[4] = {3,0,1,2};
        int l_dir[4] = {3,2,1,0};
        step2(u_dir,ur);
        step2(l_dir,lr);
    }
    cal_res();
    cout << res;
    return 0;
}