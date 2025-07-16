#include <iostream>
#include <vector>
#include <algorithm>

#define T 1000004

using namespace std;
using ll = long long;

ll N{},res{},a[T],cnt[T],prev_idx[T];
vector<ll> v;

void go(int i){
    if( i == -1) return;
    v.push_back(a[i]);
    go(prev_idx[i]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    fill(&a[0],&a[0] + T,0);
    fill(&cnt[0],&cnt[0] + T,1);
    fill(&prev_idx[0],&prev_idx[0] + T,-1);

    ll idx{};
    for(ll i{}; i < N; ++i){
        scanf("%lld",&a[i]);
    }

    for(ll i{}; i < N; ++i){
        for(ll j{}; j < i; ++j){
            if(a[j] < a[i] && cnt[i] < cnt[j] + 1){
                cnt[i] = cnt[j] + 1;
                prev_idx[i] = j;
                if(res < cnt[i]){
                    res = cnt[i];
                    idx = i;
                }
            }
        }
    }

    go(idx);
    cout << res <<"\n";
    reverse(v.begin(),v.end());
    for(auto e : v){
        cout << e << " ";
    }
    return 0;
}