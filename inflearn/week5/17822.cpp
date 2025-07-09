#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <limits>
using namespace std;

const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
int N{},M{},T{},db[54][54],ndb[54][54],res{};
vector<tuple<int,int,int>> info;
void show_db(int src[54][54]){
    cout << endl << endl;
    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            cout << src[r][c] << " ";
        }
        cout << endl;
    }
}

void rotate(tuple<int,int,int> e, int src[54][54], int dst[54][54]){
    int x = get<0>(e), d = get<1>(e), k = get<2>(e);
    memcpy(dst,src,sizeof(int)*54*54);
    int cnt{1};
    while(x * cnt <= N){
        for(int r{}; r < N; ++r){
            if(r == x * cnt -1){
                for(int c{}; c < M; ++c){
                    dst[r][(c + d*k + M) % M] = src[r][c];
                }
            }
        }
        cnt++;
    }
}

pair<int,int> check_neighbor(int r, int c, int src[54][54], int dst[54][54]){
    int cnt{},cnt_left{};
    if(src[r][c] == 0) return {cnt,cnt_left};
    else cnt_left++;
    for(int i{}; i < 4; ++i){
        int nr = r + dr[i];
        int nc = (c + dc[i] + M) % M;
        if(nr < 0 || nr >= N) continue;
        if(src[nr][nc] == src[r][c]) {
            cnt++;
            dst[nr][nc] = 0;
        }
    }
    if(cnt) dst[r][c] = 0;
    return {cnt,cnt_left};
}

void count_left(int src[54][54]){
    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            if(src[r][c]) res += src[r][c];
        }
    }
}

void solve(){
    for(auto e : info){
        rotate(e,db,ndb);
        memcpy(db,ndb,sizeof(int)*54*54);

        int sum_cnt{},sum_v{},sum_left{};
        pair<int,int> sum_info;
        for(int r{}; r < N; ++r){
            for(int c{}; c < M; ++c){
                sum_info = check_neighbor(r, c,db,ndb);
                sum_cnt += sum_info.first; sum_left += sum_info.second;
                sum_v += ndb[r][c];
            }
        }
        if(sum_cnt == 0){
            for(int r{}; r < N; ++r){
                for(int c{}; c < M; ++c){
                    if(ndb[r][c] == 0) continue;
                    if(float(ndb[r][c]) > float(sum_v) / float(sum_left)) {
                        ndb[r][c] = ndb[r][c] - 1;
                    }
                    else if(float(ndb[r][c]) < float(sum_v)/float(sum_left)) {
                        ndb[r][c] = ndb[r][c] + 1;
                    }
                }
            }
        }
        memcpy(db,ndb,sizeof(int)*54*54);
    }
}

int main(){
    cin >> N >> M >> T;
    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            cin >> db[r][c];
        }
    }
    for(int t{}; t < T; ++t){
        int x{},d{},k{};
        cin >> x >> d >>k;
        d *= -1;
        if(d == 0) d = 1;
        info.emplace_back(x,d,k);//1이 시계방향
    }

    solve();

    count_left(ndb);
    cout << res;
    return 0;
}