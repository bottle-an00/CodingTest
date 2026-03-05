#include <iostream>
#include <string>

using namespace std;
int N;
string min_ans, max_ans, dp[102], a, MAX_STRING;

string get_min(string a, string b){
    if(a.size() != b.size()) return (a.size() < b.size()) ? a : b;
    return (a < b) ? a : b;
}

string find_max(int n){
    int len = n /2;
    string ret;
    if(n % 2) ret.push_back(a[3]);
    else ret.push_back(a[2]);
    for(int i{}; i < len-1; ++i){
        ret.push_back(a[2]);
    }
    return ret;
}

string find_min(int n){
    for(int i{2}; i <= 7; ++i){
        dp[i] = a[i];
        if(i == 6) dp[i] = '6';
    }

    for(int i{8}; i <= n; ++i){
        for(int k{2}; k <= 7; ++k){

            if((i - k) >= 2 && dp[i-k].size() != 102){
                string cand = dp[i-k];
                cand.push_back(a[k]);
                dp[i] = get_min(dp[i], cand);
            }
        }
    }

    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //db for finding minima
    a = "00174208";
    for(int i{}; i < 102; ++i) MAX_STRING.push_back('9');

    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        fill(&dp[0],&dp[0] + 102,MAX_STRING);
        //find max
        max_ans = find_max(num);
        //find_min
        min_ans = find_min(num);

        cout << min_ans << " " << max_ans << "\n";
    }

    return 0;
}