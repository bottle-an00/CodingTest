#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0 ,1};
int N{}, res{},sx{},sy{},d{},g{}, db[102][102];

void make_dragon(int g){
    vector<int> v;
    v.emplace_back(d);// 0세대

    while(g){
        vector<int> next;
        next.assign(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(auto e : v){
            int n_d = e;
            n_d = (n_d + 2) % 4;
            n_d = (n_d -1 + 4) % 4;
            next.push_back(n_d);

        }

        v.assign(next.begin(),next.end());
        g--;
    }

    db[sy][sx] = 1;
    for(auto e : v){
        sy += dy[e];
        sx += dx[e];
        if(sy >=0 && sx >=0 && sy <= 100 && sx <= 100) db[sy][sx] = 1;
    }
}

int main(){
    cin >> N;
    fill(&db[0][0],&db[0][0]+102*102,0);

    for(int i{}; i < N; ++i){
        cin >> sx >> sy >> d >> g;
        make_dragon(g);
    }
    for(int i{}; i <= 10000; ++i){
        if(db[(i%100)][(i/100)] && db[(i%100)+1][(i/100)] 
            && db[(i%100)][(i/100)+1]  && db[(i%100)+1][(i/100)+1] ){
                res++;
        }
    }
    cout << res;
    return 0;
}