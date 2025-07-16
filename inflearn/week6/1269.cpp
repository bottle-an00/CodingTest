#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N{}, M{},res{};
vector<int> a,b;
int solve(vector<int> tgt, vector<int> src){
    int cnt{};
    for(auto e : tgt){
        int idx = lower_bound(src.begin(),src.end(),e) - src.begin();
        if(e != src[idx]){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> N >> M;
    a.assign(N,0);
    b.assign(M,0);

    for(int i{};i < N; ++i){
        cin >> a[i];
    }
    for(int i{};i < M; ++i){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    res = solve(a,b) + solve(b,a);
    cout << res;
    return 0;
}