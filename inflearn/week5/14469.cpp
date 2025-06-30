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

    // sort(info.begin(),info.end(),[](pair<int,int> a , pair<int,int> b){
    //     //여기서부터
    //     if(a.first < b.first) return true;
    //     else if (a.first == b.first){
    //         return (a.second > b.second) ? true : false;
    //     }
    //     //여기는 단순히 sort로 바꿔도 무방 -> 나는 무조건 긴 것부터 와야 한다고 생각했는데 이는 오름차순으로 시작 시간이 먼저인 것부터 하므로 상관없음
    //     return false;   
    // });
    sort(info.begin(), info.end());
    for(auto e : info){
        cout << e.first <<", " << e.second << endl;
    }
    for(int i{}; i < n; ++i){
        int a_t = info[i].first;
        int t_t = info[i].second;
        if(res < a_t) res = a_t + t_t;
        else res += t_t;
    }

    cout << res;

    return 0;
}
