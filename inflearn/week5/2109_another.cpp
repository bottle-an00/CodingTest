#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n{},p{},d{},res{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int,int>> info;
    
    cin >> n;
    for(int i{}; i < n; ++i){
        cin >> p >> d;
        info.emplace_back(d,p);
    }
    
    sort(info.begin(),info.end());

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i{}; i <n; ++i){
        pq.push(info[i].second);
        if(pq.size() > info[i].first){
            pq.pop();
        }       
    }
    while(pq.size()){
        res += pq.top();
        pq.pop();
    }
    cout << res; 

    return 0;
}