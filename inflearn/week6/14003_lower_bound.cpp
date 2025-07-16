#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;

const int T = 1000004;

ll N;
ll a[T], dp_idx[T], before[T];

vector<ll> lis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(ll i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<ll> v;
    ll len = 0;
    
    for(ll i = 0; i < N; ++i){
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        ll pos = it - v.begin();
        if(it == v.end()){
            v.push_back(a[i]);
        } else {
            *it = a[i];
        }
        dp_idx[i] = pos;
        // LIS 수열 재구성을 위한 추적용
        if(pos == 0) before[i] = -1;
        else {
            for(ll j = i - 1; j >= 0; --j){
                if(dp_idx[j] == pos - 1 && a[j] < a[i]){
                    before[i] = j;
                    break;
                }
            }
        }
    }

    // LIS 길이
    cout << v.size() << "\n";

    // LIS 수열 역추적
    stack<ll> stk;
    ll idx = -1;
    ll target = v.size() - 1;
    for(ll i = N - 1; i >= 0; --i){
        if(dp_idx[i] == target){
            stk.push(a[i]);
            target--;
        }
    }

    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
