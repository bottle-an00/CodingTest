#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

ll N{},M{},sum{},max_l{numeric_limits<ll>::min()};
pair<ll,ll> res{0,0};
vector<ll> info;

bool is_possible(int mid){
    ll cnt{};
    for(auto e : info){
        cnt += e / mid;
    }
    
    if(cnt >= M) {
        res.second = sum - M*mid;
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    info.assign(N,0);
    for(int i{}; i < N; ++i){
        cin >> info[i];
        sum += info[i];
        max_l = max(max_l,info[i]);
    }
    ll l{1},r{max_l};
    while(l <= r){
        ll mid = (l + r) / 2;
        if(is_possible(mid)){
            res.first = max(res.first, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << res.second;
    return 0;
}