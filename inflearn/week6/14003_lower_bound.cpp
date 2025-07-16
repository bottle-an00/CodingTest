#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int T = 1000004;

ll N{}, a[T], cnt[T], prev_idx[T], tracking[T];

void print_lis(ll idx) {
    if (idx == -1) return;
    print_lis(prev_idx[idx]);
    cout << a[idx] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(ll i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<ll> v;
    ll idx{};
    for(ll i = 0; i < N; ++i){
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        ll pos = it - v.begin();
        if(it == v.end()){
            v.push_back(a[i]);
        } else {
            *it = a[i];
        }
        cnt[i] = pos;
        
        if(pos == 0) prev_idx[i] = -1;
        else {
            prev_idx[i] = tracking[pos - 1];
            if(cnt[i] == v.size() - 1) idx = i;
        }
        tracking[pos] = i;
    }

    cout << v.size() << "\n";
    print_lis(idx);

    return 0;
}
