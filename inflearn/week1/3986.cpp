#include <bits/stdc++.h>
using namespace std;

bool check_chill_word(const string& input_str) {
    stack<char> status;
    for (char ch : input_str) {
        if (!status.empty() && status.top() == ch) {
            status.pop(); 
        } else {
            status.push(ch); 
        }
    }
    return status.empty(); 
}


int main(){
    int N{};
    cin >> N;

    int cnt{};
    for(int i = 0 ; i < N; ++i){
        string input;
        cin >> input;
        if(check_chill_word(input)) ++cnt; 
    }

    cout << cnt << endl;

    return 0;
}