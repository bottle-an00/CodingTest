#include <iostream>
#include <string>

using namespace std;
using ii = pair<int,int>;
int N{},M{},dp[10002];
ii a[5002];
int price_convertor(string input){
    size_t pos_ = input.find('.');
    int p1 = stoi(input.substr(0,pos_));
    int p2 = stoi(input.substr(pos_ + 1,2));
    return p1*100 + p2;
}

int dfs(int m){
    int &res = dp[m];
    if(res != -1) return res;
    int max_res{};
    for(int i{}; i < N; ++i){
        if(m >= a[i].second){
            max_res = max(max_res, dfs(m - a[i].second) + a[i].first);
        }
    }
    return res = max_res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1){
        string M_input;
        cin >> N >> M_input;
        M = price_convertor(M_input);
        if(N == 0 && M == 0) break;

        for(int i{}; i < N; ++i){
            string p; int c;
            cin >> c >> p;
            a[i] = {c,price_convertor(p)};
        }

        fill(&dp[0],&dp[0]+10002,-1);
        cout << dfs(M) << "\n";
    }
    return 0;
}