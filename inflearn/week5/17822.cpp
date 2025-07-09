#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
int N{},M{},T{},db[54][54],ndb[54][54],res{};
vector<tuple<int,int,int>> info;
void rotate(tuple<int,int,int> e, int src[54][54], int dst[54][54]){
    memcpy(dst,src,sizeof(int)*54*54);
    int cnt{1};
    while(get<0>(e)*cnt < N){
        for(int r{}; r < N; ++r){
            if(r == get<0>(e)*cnt){
                for(int c{}; c < M; ++c){
                    
                }
            }
        }
        cnt++;
    }
}

void check_neighbor(){

}

void solve(){
    for(auto e : info){
        rotate(e,db,ndb);
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