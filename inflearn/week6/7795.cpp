#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N{}, T{}, M{};
vector<int> A,B;
void solve(){
    int res{};
    for(int i{}; i < A.size(); ++i){
        int l{},r{static_cast<int>(B.size()) - 1},mid{},cnt{};
        while(l <= r){
            mid = (l + r) / 2;
            if(A[i] > B[mid]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(A[i] > B[mid]) ++mid;
        res += mid;
    }
    cout << res << endl;
}

int main(){
    cin >> T;
    for(int t{}; t < T; ++t){
        cin >> N >> M;

        A.assign(N,0);
        B.assign(M,0);

        for(int n{}; n < N; ++n){
            cin >> A[n];
        }
        for(int m{}; m < M; ++m){
            cin >> B[m];
        }

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        solve();
    }
    return 0;
}