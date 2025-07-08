#include <iostream>
#include <limits>
using namespace std;
int N{},a[100001],psum[100001],res{numeric_limits<int>::min()};

int main(){
    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    for(int interval{1}; interval <= N; ++interval){
        for(int start{interval}; start <= N; ++start){
            int sum = psum[start] - psum[start-interval];
            res = max(res, sum);
            if(interval == N) break;
        }
    }
    cout << res;
    return 0;
}