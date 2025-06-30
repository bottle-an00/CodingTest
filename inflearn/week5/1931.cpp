#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N{},s{},d{},res{},cur_d{};
    vector<pair<int,int>> info;
    cin >> N;
    for(int i{}; i < N; ++i){
        cin >> s >> d;
        info.emplace_back(d,s);
    }
    sort(info.begin(),info.end());
    for(int i{}; i < N; ++i){
        if(info[i].second < cur_d) continue;
        cur_d = info[i].first;
        res++;
    }
    cout << res;
    return 0;
}