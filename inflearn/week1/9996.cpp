#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string pattern;
    cin >> pattern;
    auto pivot = pattern.find("*");
    
    string pattern_f = pattern.substr(0,pivot);
    string pattern_b = pattern.substr(pivot+1,pattern.size());

    vector<string> inputs(N);
    for(int i =0; i < N; ++i){
       cin >> inputs[i];
    }

    for(int i = 0 ; i < N; ++i){
        if((pattern_f.size() + pattern_b.size()) > inputs[i].size()) {
            cout << "NE" << endl;
            continue;
        }

        string intput_f = inputs[i].substr(0,pattern_f.size());
        string intput_b = inputs[i].substr(inputs[i].size() - pattern_b.size(), inputs[i].size());

        if(intput_f == pattern_f &&intput_b == pattern_b) cout << "DA" << endl;
        else cout << "NE" << endl;
    }
    return 0;
}