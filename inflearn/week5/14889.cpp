#include <iostream>
#include <vector>
using namespace std;

int N, db[24][24], res = __INT_MAX__;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> db[i][j];

    for(int i = 0; i < (1 << N); ++i){
        if(__builtin_popcount(i) != N / 2) continue;
        if(i > ((1 << N) - 1) - i) continue; 

        int s[2] = {};
        for(int k = 0; k < N; ++k){
            for(int l = k+1; l < N; ++l){
                int k_team = (i & (1 << k)) ? 1 : 0;
                int l_team = (i & (1 << l)) ? 1 : 0;
                if(k_team == l_team)
                    s[k_team] += db[k][l] + db[l][k];
            }
        }
        res = min(res, abs(s[0] - s[1]));
    }

    cout << res;
    return 0;
}
