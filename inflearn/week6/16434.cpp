#include <iostream>
#include <limits>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;

ll N{},H_max{},H_atk{},H_cur{},res{numeric_limits<ll>::max()};
vector<tuple<ll,ll,ll>> info;

bool go(ll mid, ll init_atk){
    H_max = mid;
    H_cur = H_max;
    ll h_atk = init_atk;
    for(int i{}; i < N; ++i){
        ll t = get<0>(info[i]);
        ll a = get<1>(info[i]);
        ll h = get<2>(info[i]);
        if(t == 2){
            h_atk += a;
            H_cur += h;
            H_cur = min(H_max, H_cur);
        } // 포션
        else{

            H_cur -= a*(h/h_atk);
            if(h % h_atk == 0) H_cur += a;
            if(H_cur <= 0) return false;
        }//몬스터
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> H_atk;
    for(int i{}; i < N; ++i){
        ll t,a,h;
        cin >> t >> a >> h;
        info.emplace_back(t,a,h);
    }
    ll l{},r{numeric_limits<ll>::max()};
    while(l <= r){
        ll mid = (l + r) / 2;

        if(go(mid,H_atk)){
            res = min(res,mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}