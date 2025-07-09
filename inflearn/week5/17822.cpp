#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
int N{},M{},T{},db[54][54],ndb[54][54],res{};
vector<tuple<int,int,int>> info;
void rotate(tuple<int,int,int> e, int src[54][54], int dst[54][54]){
    int x = get<0>(e), d = get<1>(e), k = get<2>(e); 
    memcpy(dst,src,sizeof(int)*54*54);
    int cnt{1};
    while(x * cnt < N){
        for(int r{}; r < N; ++r){
            if(r == x * cnt){
                for(int c{}; c < M; ++c){
                    dst[r][(c + d*k + M) % M] = src[r][c];
                }
            }
        }
        cnt++;
    }
}

void check_neighbor(int r, int c, int src[54][54]){
    int cnt{};
    for(int i{}; i < 4; ++i){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(src[nr][nc] == src[r][c]) {
            cnt++;
            src[nr][nc] = 0;
        }
    }
    if(cnt) src[r][c] = 0;
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

        for(int r{}; r < N; ++r){
            for(int c{}; c < M; ++c){
                check_neighbor(r, c,ndb);
            }
        }
        memcpy(db,ndb,sizeof(int)*N*M);
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
        if(d == 0) d = 1;
        info.emplace_back(x,-1*d,k);//1이 시계방향
    }

    solve();
    cout << res;
    return 0;
}