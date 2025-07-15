#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using ll = long long;

ll N{}, M{}, max_t{};
vector<int> a;

bool go(ll mid){
    ll cnt = M;
    for(auto e : a){
        cnt += mid / e;
    }
    return cnt >= N;
}

int main(){
    cin >> N >> M;
    a.assign(M, 0);
    for(int i = 0; i < M; ++i){
        cin >> a[i];
        max_t = max(max_t,static_cast<ll>(a[i]));
    }

    if(N <= M){
        cout << N << '\n';
        return 0;
    }

    ll l = 0, r = N*max_t, res = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(go(mid)){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    ll before = M;
    for(auto e : a){
        before += (res - 1) / e;
    }
    ll remain = N - before;

    for(int i = 0; i < M; ++i){
        if(res % a[i] == 0){
            if(--remain == 0){
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
