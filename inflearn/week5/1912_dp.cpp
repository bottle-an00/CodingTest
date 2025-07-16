#include <iostream>
#include <limits>
using namespace std;
int N{},a[100001],dp[100001],res{};

int main(){
    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> a[i];
    }

    dp[1] = a[1]; res = dp[1];
    for(int i{2}; i <= N; ++i){
        dp[i] = max(dp[i-1]+ a[i],a[i]);
        res = max(res,dp[i]);       
    }
    cout << res;
    return 0;
}