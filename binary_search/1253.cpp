#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> db;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i{}; i < N; ++i){
        int e;
        cin >> e;
        db.emplace_back(e);
    }

    int ans{};
    sort(db.begin(),db.end());
    for(int idx{0}; idx < N; ++idx){
        bool good = false;

        for(int j{}; j < N; ++j){
            if(j == idx) continue;

            int target = db[idx] - db[j];

            int l = lower_bound(db.begin(), db.end(), target) - db.begin();
            int r = upper_bound(db.begin(), db.end(), target) - db.begin();

            for(int k = l; k < r; ++k){
                if(k == j || k == idx) continue;
                good = true;
                break;
            }

            if(good) break;
        }

        if(good) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}
