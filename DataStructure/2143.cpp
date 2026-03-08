#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
int T, nA, nB;
long long ans;
vector<int> A_elem, B_elem;
vector<int> A_psum, B_psum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    cin >> nA;
    A_elem.resize(nA);
    for (int i = 0; i < nA; i++) {
        cin >> A_elem[i];
    }
    for (int i = 0; i < nA; i++) {
        int sum = 0;
        for (int j = i; j < nA; j++) {
            sum += A_elem[j];
            A_psum.push_back(sum);
        }
    }

    cin >> nB;
    B_elem.resize(nB);
    for (int i = 0; i < nB; i++) {
        cin >> B_elem[i];
    }
    for (int i = 0; i < nB; i++) {
        int sum = 0;
        for (int j = i; j < nB; j++) {
            sum += B_elem[j];
            B_psum.push_back(sum);
        }
    }
    sort(B_psum.begin(),B_psum.end());

    for(int i{}; i < A_psum.size(); ++i){
        int need = T - A_psum[i];

        auto l = lower_bound(B_psum.begin(), B_psum.end(), need);
        auto r  = upper_bound(B_psum.begin(), B_psum.end(),need);

        ans += r - l;
    }

    cout << ans <<"\n";

    return 0;
}