#include <bits/stdc++.h>
using namespace std;

template<typename T> void chmin(T& a, T b){
    if(a > b) a = b;
}
template<typename T> void chmax(T& a, T b){
    if(a < b) a = b;
}

int main(){
    int A,B,C;
    cin >> A >> B >> C;

    int min_at {numeric_limits<int>::max()};
    int max_lt {numeric_limits<int>::min()};
    
    vector<pair<int,int>> info;
    for(int i = 0; i <3; ++i){
        int at, lt;
        cin >> at >> lt;
        chmin(min_at,at);chmax(max_lt,lt);
        info.emplace_back(at,lt);
    }
    
    vector<int> fee_info(max_lt - min_at + 1,0);
    for(int i = 0 ; i < (int)info.size(); ++i){
        int s = info[i].first - min_at;
        int t = info[i].second - min_at;

        for(int j = s; j < t; ++j) ++fee_info[j];
    }

    int res{};
    for(int i = 0; i < max_lt - min_at+1; ++i){
        switch(fee_info[i]){
            case(1):
                res += A;
                break;
            case(2):
                res += B*2;
                break;
            case(3):
                res += C*3;
                break;
        }
    }

    cout << res;
    
    return 0;
}