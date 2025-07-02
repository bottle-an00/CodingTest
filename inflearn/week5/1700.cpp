#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii=pair<int,int>;

int N{}, K{}, res{};
int main(){
    cin >> N >> K;

    vector<int> s,l;
    for(int i{}; i < K; ++i){
        int e{};
        cin >> e;
        s.push_back(e);
    }

    for(int i{}; i < K; ++i){
        if(find(l.begin(),l.end(),s[i]) != l.end()) continue;

        if(l.size() < N) {l.push_back(s[i]); continue;}

        int idx{-1}, f{-1};
        for(int j{}; j < N; ++j){
            int next_use = __INT_MAX__;
            for(int k{i+1}; k < K; ++k){
                if(s[k] == l[j]){
                    next_use = k;
                    break;
                }
            }
            if(next_use > f){
                f = next_use;
                idx = j;
            }
        }
        l[idx] = s[i];
        res++;
    }
    cout << res;
    return 0;
}