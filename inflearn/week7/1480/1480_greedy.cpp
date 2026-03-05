#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, C, ans;
vector<int> a, bag;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

int main(){
    fast_io();
    cin >> N >> M >> C;
    a.reserve(N);
    bag.assign(M,C);

    for(int i{}; i < N; ++i){
        int w;
        cin >> w;
        a.emplace_back(w);
    }

    for(auto e : a){
        sort(a.begin(),a.end());
        int idx = lower_bound(bag.begin(),bag.end(),e) - bag.begin();
        cout << idx << endl;
        if(idx == M) break;
        bag[idx] -= e;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}