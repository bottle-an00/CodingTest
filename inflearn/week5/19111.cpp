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
    reverse(db.begin(),db.end());

    int l{};
    while(1){
        if(l >= db.back().first && l < db.back().second) {
            l += L;
            cnt++;
        }
        else l++;
        while(db.size() && l >= db.back().second) db.pop_back();
        if(db.empty()) break;
    }

    cout << cnt;
    return 0;
}