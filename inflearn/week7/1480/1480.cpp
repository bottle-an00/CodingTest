#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, C;
vector<int> a, bag;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

int main(){
    fastIO();
    cin >> N >> M >> C;
    a.reserve(N);
    bag.assign(M,C);

    for(int i{}; i < N; ++i){
        int w;
        cin >> w;
        a.emplace_back(w);
    }

    //main_logic -> greedy
    sort(a.begin(),a.end());
    for(auto e : a){
        int idx = lower_bound(bag.begin(),bag.end(),e) - bag.begin();
        bag[idx] -= e;

    }
    return 0;
}