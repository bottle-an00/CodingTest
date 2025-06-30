#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N{},K{},M{},V{},C{};
    long long res{};
    vector<pair<int,int>> j;
    vector<int> b;
    
    cin >> N >> K;
    for(int i{}; i < N; ++i){
        cin >> M >> V;
        j.emplace_back(M,V);
    }
    for(int i{}; i < K; ++i){
        cin >> C;
        b.push_back(C);
    }

    sort(b.begin(),b.end());
    sort(j.begin(),j.end());

    priority_queue<int,vector<int>, less<int>> pq;
    int n{};
    for(int i{}; i < K; ++i){
        while(n < N && b[i] >= j[n].first) pq.push(j[n++].second);
        
        if(pq.size()){
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
    return 0;
}