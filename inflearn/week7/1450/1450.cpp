#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
long long C, ans;
vector<long long> sum_L, sum_R;
vector<int> a;

void getSum(const vector<long long>& source, int idx, int sum, vector<long long>& out){
    if(sum > C) return;
    if(idx == source.size()){
        out.push_back(sum);
        return;
    }

    getSum(source, idx + 1, sum + source[idx], out);
    getSum(source, idx + 1, sum, out);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> C;
    a.resize(N);
    for(int i{}; i < N; ++i) cin >> a[i];

    vector<long long> left(a.begin(), a.begin() + N/2);
    vector<long long> right(a.begin() + N/2, a.end());

    getSum(left, 0,0,sum_L);
    getSum(right, 0,0,sum_R);

    sort(sum_R.begin(), sum_R.end());
    for(int i{}; i < sum_L.size(); ++i){
        if( sum_L[i] <= C){
            ans += upper_bound(sum_R.begin(),sum_R.end(), C - sum_L[i]) - sum_R.begin();
        }
    }
    cout << ans << "\n";
    return 0;
}