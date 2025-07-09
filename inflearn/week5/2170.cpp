#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N{};
long long sum{};
vector<pair<long long, long long>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> N;
    v.assign(N,pair<long long, long long>(0,0));
    for(int i{}; i < N; ++i){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());

    long long ss{v[0].first};
    long long dd{v[0].second};
    for(int i{}; i < N-1; ++i){
        if(dd < v[i+1].first){
            sum += dd - ss;
            ss = v[i+1].first;
            dd = v[i+1].second;
        }
        else{
            dd = max(dd,v[i+1].second);
        }
    }
    sum += dd - ss;
    cout << sum;
    return 0;
}