#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N{}, res{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    vector<int> info(N+1);
    for(int i{}; i < N; ++i) {cin >> info[i];}
    
    int l{},r{};
    vector<int> v;
    v.push_back(info[l]);
    while(true){
        bool y = (find(v.begin(),v.end(), info[r]) != v.end()) ? true : false;
        if(y) l++;
        else {
            r++; res++;
            v.push_back(info[r]);
        }
        if(r == N) break;
    }
    cout << res;
    return 0;
}