#include <bits/stdc++.h>
using namespace std;

int main(){
    string input_str;
    
    cin >> input_str;

    int start_idx = static_cast<int>('a');
    int end_idx = static_cast<int>('z');

    vector<int> res(end_idx - start_idx + 1 ,0);
    for(int i = 0; i < input_str.size(); ++i){
        int index = input_str[i] - start_idx;
        ++res[index];
    }

    for(auto count : res) cout << count << " ";

    return 0;
}