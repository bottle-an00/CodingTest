#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N, db[500002], min_e, max_e,sum{};
vector<int> mp;
const int INT_MAX = 1e9;
const int INT_MIN = -1 * 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    fill(&db[0], &db[0] + 500002, 0);
    min_e = INT_MAX; max_e = INT_MIN;
    mp.assign(8002,0);
    for(int i{}; i < N; ++i){
        cin >> db[i];
        min_e = min(min_e , db[i]);
        max_e = max(max_e, db[i]);
        sum += db[i];
        
        mp[db[i]+4000]++;
    }
    //산술평균
    cout << (int)round((double)sum / N) << "\n";
    //중앙값
    sort(db, db + N);
    cout << db[N/2] << "\n";
    //최빈값
    int maxFreq = 0;
    for(int i = 0; i < 8001; ++i)
        maxFreq = max(maxFreq, mp[i]);

    int mode = 0;
    bool first = true;

    for(int i = 0; i < 8001; ++i){
        if(mp[i] == maxFreq){
            if(first){
                mode = i - 4000;
                first = false;
            } else {
                mode = i - 4000;
                break;
            }
        }
    }
    cout << mode << "\n";
    
    //범위
    cout << max_e - min_e << "\n";

    return 0;
}