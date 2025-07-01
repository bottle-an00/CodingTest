#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N{};
long long res{};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    vector<int> info(N+1);
    for(int i{}; i < N; ++i) {cin >> info[i];}

    int r{};
    vector<int> v(N+1,0);
    for(int l{}; l < N; ++l){
        while(r < N && v[info[r]] == 0){
            v[info[r++]] = 1;
        }
        res += r - l;
        v[info[l]] = 0;
    }
    cout << res;
    return 0;
}