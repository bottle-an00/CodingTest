#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const ii dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int N{}, M{}, K{}, db[54][54],tdb[54][54],res{__INT_MAX__};
vector<iii> info;
vector<int> v;

int cal_res(){
    for(int r{}; r < N; ++r){
        int sum{};
        for(int c{}; c < M; ++c){
            sum += tdb[r][c];
        }
        res = min(res, sum);
    }
    return res;
}

void go(){
    do{
        memcpy(tdb,db,sizeof(db));
        for(int idx{}; idx < K; ++idx){
            int r{get<0>(info[v[idx]])},c{get<1>(info[v[idx]])}, S{get<2>(info[v[idx]])};
            for(int s{1}; s <= S; ++s){
                int cr{r-s},cc{c-s},i{};
                int prev{tdb[r-s][c-s]};
                while(1){
                    int nr = cr + dir[i].first;
                    int nc = cc + dir[i].second;

                    if(nr == r-s && nc == c-s) {
                        tdb[nr][nc] = prev;
                        break;
                    }
                    if(nr < r-s || nc < c-s || nr > r + s || nc > c + s){
                        i = (i + 1)%4; 
                        continue;
                    }
                    int next{tdb[nr][nc]};
                    tdb[nr][nc] = prev;
                    prev = next;
                    cr = nr; cc = nc;
                }
            }
        }
        cal_res();
    }while(next_permutation(v.begin(),v.end()));
}

int main(){
    cin >> N >> M >> K; 
    fill(&db[0][0], &db[0][0] + 54*54,0);

    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            cin >> db[r][c];
        }
    }

    for(int k{}; k < K; ++k){
        int r{},c{},s{};
        cin >> r >> c >> s;
        info.emplace_back(--r,--c,s);
        v.push_back(k);
    }
    go();
    cout <<res;
    return 0;
}