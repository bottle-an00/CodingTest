#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    getline(cin,input);

    for(int i =0; i < input.size(); ++i){
        if(input[i] >= 'a' && input[i] <= 'z') input[i] = (input[i] + 13 - 'a') % ('z'-'a'+1) + 'a';
        else if(input[i] <= 'Z' && input[i] >= 'A') input[i] = (input[i] + 13 - 'A') % ('Z'-'A'+1) + 'A';
    }

    cout << input;
    return 0;
}