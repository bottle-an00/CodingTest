#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> pikachu = {"pi","ka","chu"};

bool solve_14405(string input_str){
    if(input_str.empty()) return false;

    bool changed = true;
    
    while (changed) {
        changed = false;
        for (const string& e : pikachu) {
            size_t pos = input_str.find(e);
            if (pos != string::npos) {
                for(int i =pos; i < pos + e.size(); ++i){
                    input_str[i] = '0';
                }
                changed = true;
                break; 
            }
        }
    }
    for(auto e : input_str){
        if(e != '0') return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    
    string input_str;
    getline(cin,input_str);
    
    cout << (solve_14405(input_str) ? "YES" : "NO") << "\n";
    return 0;
}