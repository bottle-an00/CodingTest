#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n{},p{},d{},max_d{},res{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int,int>> info;
    
    cin >> n;
    for(int i{}; i < n; ++i){
        cin >> p >> d;
        max_d = max(max_d, d);
        info.emplace_back(d,p);
    }
    
    sort(info.begin(),info.end(),[](const pair<int,int> a, const pair<int,int> b){return b < a;});

    priority_queue<int> pq;
    int idx{};
    for(int i{max_d}; i >= 1; --i){
        while(idx < n && info[idx].first >= i) pq.push(info[idx++].second);
        if(pq.size()){
            res += pq.top(); pq.pop();
        }
    }
    cout << res;

    return 0;
}