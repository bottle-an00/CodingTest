#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N{},X{};
long long res{};

int main(){
    cin >> N;
    vector<int> v(N);
    for(int i{}; i < N; ++i) cin >> v[i];
    cin >> X;

    sort(v.begin(),v.end());

    int l{},r{N-1};
    while(l < r){
        if(v[l] + v[r] == X) res++;

        if(v[l] + v[r] < X) l++;
        else r--;
    }
    cout << res;
    return 0;
}