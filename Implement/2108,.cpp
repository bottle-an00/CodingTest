#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int INT_MAX = 1e9;
const int INT_MIN = -1 * 1e9;

int N, db[500002], freq[8001], max_e{INT_MIN}, min_e{INT_MAX}, sum{0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    fill(&db[0],&db[0] + 500002,0);
    fill(&freq[0],&freq[0] + 8001,0);

    for(int i{}; i < N; ++i){
        cin >> db[i];

        max_e = max(max_e, db[i]);
        min_e = min(min_e, db[i]);
        freq[db[i]+4000]++;
        sum += db[i];
    }

    // 산술평균
    cout << (int)round((double)sum / N) <<"\n";
    // 중앙값
    sort(db,db+N);
    cout << db[N/2] << "\n";
    // 최빈값
    int max_freq{};
    for(int i{}; i < 8001; ++i){
        max_freq = max(max_freq, freq[i]);
    }
    bool first;
    vector<int> max_freq_vec;
    for(int i{}; i < 8001; ++i){
        if(freq[i] == max_freq) max_freq_vec.emplace_back(i-4000);
    }
    if(max_freq_vec.size() >= 2) cout << max_freq_vec[1] << "\n";
    else cout << max_freq_vec[0] << "\n";

    // 범위
    cout << max_e - min_e << "\n";
    return 0;
}