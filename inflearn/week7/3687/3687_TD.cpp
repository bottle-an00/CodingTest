#include <iostream>
#include <string>

using namespace std;
int N, num;
string min_ans, max_ans, dp[102], a, MAX_STRING;

string get_min(string a, string b){
    if(a.size() != b.size()) return (a.size() < b.size()) ? a : b;
    return (a < b) ? a : b;
}

string find_max(int n){
    int len = n /2;
    string ret;
    if(n % 2) ret.push_back('7');
    else ret.push_back('1');
    for(int i{}; i < len-1; ++i){
        ret.push_back('1');
    }
    return ret;
}

string find_min(int n){
    if(n == 0) return "";

    string ret = dp[n];
    if(ret != MAX_STRING) return ret;

    for(int k{}; k <= 9; ++k){
        if(n - (a[k] - '0') < 0) continue;
        //초기 0 불가
        if(n == num && k == 0) continue;

        ret = get_min(ret, to_string(k) + find_min(n - (a[k] - '0')));
    }

    dp[n] = ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //db for finding minima
    a = "6255456376";
    for(int i{}; i < 102; ++i) MAX_STRING.push_back('9');

    cin >> N;
    for(int i = 0; i < N; i++){
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