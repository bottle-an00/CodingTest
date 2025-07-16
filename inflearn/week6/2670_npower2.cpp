#include <iostream>
#include <iomanip>
using namespace std;
int N{};
double a[10004],ret{};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }
    for(int i{}; i < N;++i){
        double res{a[i]},tmp{a[i]};
        for(int len{1}; len < N - i; ++ len){
            tmp =  tmp*a[i+len];
            res = max(res,tmp);
        }
        ret = max(ret, res);
    }
    cout << fixed << setprecision(3) << ret << "\n";
    return 0;
}
