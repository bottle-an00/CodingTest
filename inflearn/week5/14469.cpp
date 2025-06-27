#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n{},a{},t{},res{};
    vector<pair<int,int>> info;
    cin >> n;
    
    for(int i{}; i < n; ++i){
        cin >> a >> t;
        info.emplace_back(a,t);
    }

    sort(info.begin(),info.end(),[](pair<int,int> a , pair<int,int> b){
        if(a.first < b.first) return true;
        else if (a.first == b.first){
            return (a.second > b.second) ? true : false;
        }
        return false;   
    });

    for(int i{}; i < n; ++i){
        int a_t = info[i].first;
        int t_t = info[i].second;
        if(res < a_t) res = a_t + t_t;
        else res += t_t;
    }

    cout << res;

    return 0;
}
