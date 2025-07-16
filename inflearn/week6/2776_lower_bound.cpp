#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T{},N{},M{};
vector<int> a,b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t{}; t < T; ++t){
        cin >> N;
        a.assign(N,0);
        for(int n{}; n < N; ++n){
            cin >> a[n];
        }
        cin >> M;
        b.assign(M,0);
        for(int m{}; m < M; ++m){
            cin >> b[m];
        }
        
        sort(a.begin(),a.end());
        
        for(auto e: b){
            int idx = lower_bound(a.begin(),a.end(),e) - a.begin();
            if(idx < a.size() && e == a[idx]) cout << "1\n";
            else cout << "0\n";
        }
        
        a.clear();
        b.clear();
    }
    return 0;
}