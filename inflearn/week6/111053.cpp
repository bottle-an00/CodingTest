#include <iostream>

using namespace std;
int N{},a[1004],cnt[1004],res{};

int main(){
    cin >> N;
    for(int i{}; i < N; ++i){
        cin >> a[i];
    }

    for(int i{}; i < N; ++i){
        for(int j{}; j < i; ++j){
            if(a[j] < a[i] && cnt[i] < cnt[j] +1){
                cnt[i] = cnt[j] + 1;
                res = max(res,cnt[i]);
            }
        }
    }
    cout << res + 1;
    return 0;
}