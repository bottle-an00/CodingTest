#include <iostream>
#include <vector>

using namespace std;
using ii = pair<int,int>;

const ii dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int N{}, M{}, K{}, db[54][54];

void show_db(){
    cout <<endl<< "-------------" << endl;
    for(int r{}; r < N; ++r){
        for(int c{}; c < M; ++c){
            cout << db[r][c] << " ";
        }
        cout << endl;
    }
}

int cal_res(){
    int res{__INT_MAX__};
    for(int r{}; r < N; ++r){
        int sum{};
        for(int c{}; c < M; ++c){
            sum += db[r][c];
        }
        res = min(res, sum);
    }
    return res;
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
        int r{},c{},S{};
        cin >> r >> c >> S;
        --r,--c;
        for(int s{1}; s <= S; ++s){
            int cr{r-s},cc{c-s},i{};
            int prev{db[r-s][c-s]};
            while(1){
                int nr = cr + dir[i].first;
                int nc = cc + dir[i].second;

                if(nr == r-s && nc == c-s) {
                    db[nr][nc] = prev;
                    break;
                }
                if(nr < r-s || nc < c-s || nr > r + s || nc > c + s){
                    i = (i + 1)%4; 
                    continue;
                }
                int next{db[nr][nc]};
                db[nr][nc] = prev;
                prev = next;
                cr = nr; cc = nc;
            }
        }
    }

    cout << cal_res();
    return 0;
}