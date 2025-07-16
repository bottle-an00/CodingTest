#include <iostream>
#include <iomanip>
using namespace std;
int N{};
double a[10004],ret{};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    double prev{1.0};
    for(int i{}; i < N; ++i){
        cin >> a[i];
        if(a[i] * prev >= a[i]){
            prev *= a[i]; 
        }else{
            prev = a[i];
        }
        ret = max(ret, prev);

    }
    cout << fixed << setprecision(3) << ret;
    
    return 0;
}
