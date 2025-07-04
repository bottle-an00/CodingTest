#include <iostream>
#include <deque>

using namespace std;
using ii = pair<int,int>;
using ic = pair<int,char>;

int N{},K{},L{},db[104][104],t{1};
int dir[2] = {0,1};
deque<ic> s;
deque<ii> dq;
ii tail;

void rotate(char D){
    int R[2][2] = {{0 , -1}, {1 , 0}};
    if( D == ('D')){
        R[0][1] = 1;
        R[1][0] = -1;
    }
    int res[2] = {0,0};

    for(int r{}; r < 2; ++r){
        for(int c{}; c < 2; ++c){
            res[r] += dir[c]*R[r][c];  
        }
    }
    dir[0] =res[0]; 
    dir[1] =res[1]; 
    s.pop_front();
}

void show_db(){
    cout << endl << endl;
    for(int r{}; r < N; ++r){
        for(int c{}; c < N; ++c){
            cout << db[r][c] << " ";
        }
        cout << endl;
    }
}

bool move(){
    ii cr = dq.front();
    tail = dq.back();
    int nr = cr.first + dir[0];
    int nc = cr.second + dir[1];
    
    if(nr < 0 || nc < 0 || nr >= N || nc >= N) return false; // 벽  
    if(db[nr][nc] == 2) return false;

    if(db[nr][nc] != 1){
        db[tail.first][tail.second] = 0;
        dq.pop_back();
    }

    dq.emplace_front(nr,nc);
    db[nr][nc] = 2;
    
    return true;
}

bool is_apple(){
     return true; // 사과
    return false;
}

int main(){
    //input 처리
    cin >> N;
    fill(&db[0][0],&db[0][0] + 104*104,0);
    cin >> K;
    for(int i{}; i < K; ++i){
        ii a;
        cin >> a.first >> a.second;
        db[a.first-1][a.second-1] = 1; // apple -> 1  
    }
    cin >> L;
    for(int i{}; i < L; ++i){
        ic r;
        cin >> r.first >> r.second;
        s.emplace_back(r);
    }

    dq.emplace_front(0,0);
    db[0][0] = 2;
    while(1){
        if(t-1 == s.front().first) rotate(s.front().second);
        if(!move()) break;
        t++;
    }
    cout << t;
    return 0;
}