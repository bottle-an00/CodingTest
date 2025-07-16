#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N{},L{},cnt{};
vector<pair<int,int>> db;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> N >> L;
    for(int i{}; i < N; ++i){
        int s{},d{};
        cin >> s >> d;
        db.emplace_back(s,d);
    }

    sort(db.begin(),db.end());
    
    int l{},b{};
    for(int i = 0; i < N; i++){
        if(l >= db[i].second) continue;
        if(l < db[i].first){
            b = (db[i].second - db[i].first) / L + (db[i].second - db[i].first) % (L ? 1 : 0);
            l = db[i].first + b * L;
        }
        else{
            b = (db[i].second - l) / L + ((db[i].second - l) % L ? 1 : 0);
            l = l + b * L;
        }
        cnt += b;
    }
    cout << cnt;
    return 0;
}