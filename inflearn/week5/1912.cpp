#include <iostream>
#include <limits>
using namespace std;
int N{},a{},sum{},res{numeric_limits<int>::min()};

int main(){
    cin >> N;
    for(int i{1}; i <= N; ++i){
        cin >> a;
        sum += a;
        res = max(res, sum);
        if(sum < 0 ) sum = 0;
    }

    cout << res;
    return 0;
}