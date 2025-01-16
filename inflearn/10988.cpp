#include <bits/stdc++.h>
using namespace std;

int solve_10988(string input_str){
    int l = 0;
    int r = static_cast<int>(input_str.size()) - 1;
    if(l == r || (int)input_str.size() == 0) {
        return 1;
    }
    
    bool is_fanlindrom = false;
    if(input_str[l] - input_str[r] == 0){
        input_str = input_str.substr(l+1,r-1);
        is_fanlindrom = solve_10988(input_str);
    }

    if(is_fanlindrom) return 1;
    
    return 0;
}

int main(){
    string input_str;
    cin >> input_str;

    cout << solve_10988(input_str); 
    return 0;
}