#include <bits/stdc++.h>
using namespace std;


int main(){
    string input_str;
    cin >> input_str;
    
    string reverse_input = input_str;
    reverse(reverse_input.begin(),reverse_input.end());

    if(reverse_input == input_str) cout << 1;
    else cout << 0;
    
    return 0;
}