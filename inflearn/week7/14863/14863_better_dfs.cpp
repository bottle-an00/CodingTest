#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
struct B { int t; ll pay; };
B a[101], b[101];

ll dp[101][100001];
bool vis[101][100001];

const ll NEG = -(1LL<<60);

ll go(int here, int rem){
    if(here == n) return 0;
    if(vis[here][rem]) return dp[here][rem];
    vis[here][rem] = true;

    ll ret = NEG;
    if(rem - a[here].t >= 0) ret = max(ret, go(here + 1, rem - a[here].t) + a[here].pay);
    if(rem - b[here].t >= 0) ret = max(ret, go(here + 1, rem - b[here].t) + b[here].pay);

    return dp[here][rem] = ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].t >> a[i].pay >> b[i].t >> b[i].pay;
    }

    cout << go(0, k) << "\n";
    return 0;
}
