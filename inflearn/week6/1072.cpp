#include <iostream>
#include <limits>

using namespace std;
long long X{},Y{},res{numeric_limits<long long>::max()};
int main(){
    cin >> X >> Y;

    if(Y*100 / X >= 99) {
        cout << -1;
        return 0;
    }

    long long l{0},r{X};
    while (l <= r){
        long long mid = (l+r)/2;
        int cal = ((Y+mid)* 100 / (X + mid));
        if(((Y+mid)* 100 / (X + mid)) > (Y* 100 / X) ){
            res = min(res,mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}