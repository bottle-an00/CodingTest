#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ii = pair<int,int>;

int T{}, K{}, db[1004][8];
vector<ii> rotation;//회전 정보
vector<ii> v;//각 톱니의 맞닿는 부분

int check_12_is_S(){
    int res{};
    for(int i{}; i < T; ++i){
        if(db[i][(v[i].first + 2)%8] == 1) res++;
    }
    return res;
}
void go(){
    for(int i{}; i < K; ++i){
        int move = rotation[i].first;
        int dir = rotation[i].second;
        int status[T];
        fill(&status[0],&status[0] + T,0);
        status[move] = dir;
        int tdir = dir;
        for(int p{move+1}; p < T; ++p){//오른쪽 방향
            tdir *= (-1);//회전 방향 지정
            if(db[p][v[p].first] == db[p-1][v[p-1].second]) break;
            status[p] = tdir;
        }
        tdir = dir;
        for(int p{move-1}; p >= 0; --p){//왼쪽 방향
            tdir *= (-1);//회전 방향 지정
            if(db[p][v[p].second] == db[p+1][v[p+1].first]) break;
            status[p] = tdir;
            
        }
        for(int t{}; t < T; ++t){
            if(status[t] != 0){
                v[t].first = (v[t].first - status[t] + 8)%8;
                v[t].second = (v[t].second - status[t] + 8)%8;
            }
        }
    }
}

int main(){
    cin >> T;
    v.assign(T,ii(6,2));
    cin.ignore();

    for(int r{}; r < T; ++r){
        string s;
        getline(cin,s);
        for(int c{}; c < 8; ++c){
            db[r][c] = s[c] - '0';
        }
    }
    cin >> K;
    for(int k{}; k < K; ++k){
        int a,b;
        cin >> a >> b;
        rotation.emplace_back(--a,b); 
    }

    go();
    cout << check_12_is_S();
    return 0;
}