#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n{}, d{}, c{},res{};
vector<pair<int,int>> dataDB;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i{}; i < n; ++i){
        cin >> d >> c;
        dataDB.emplace_back(d,c);
    }    

    sort(dataDB.begin(),dataDB.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i{}; i < n; ++i){
        pq.push(dataDB[i].second);

        if(pq.size() > dataDB[i].first){
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
