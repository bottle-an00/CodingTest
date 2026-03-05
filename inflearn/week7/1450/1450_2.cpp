#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
ll C, ans;
vector<int> a;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

void go(int here, int end, ll sum, vector<ll>& arr){
    if(sum > C) return;
    if(here > end){
        arr.push_back(sum);
        return;
    }
    go(here + 1, end, sum + a[here] ,arr);
    go(here + 1, end, sum ,arr);
    return;
}

int main(){
    fast_io();
    cin >> N >> C;
    a.resize(N);
    for(int i{}; i < N; ++i) cin >> a[i];

    vector<ll> v;
    vector<ll> v2;

    go(0, N/2 -1, 0, v);
    go(N/2,N-1,0,v2);

    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(auto e : v){
        if(e <= C){
            ans += upper_bound(v2.begin(),v2.end(), C - e) - v2.begin();
        }
    }
    cout << ans << '\n';
    return 0;
}