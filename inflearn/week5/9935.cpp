#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string input, bomb, res;
    cin >> input;
    cin >> bomb;

    for(auto c : input){
        res += c;
        int bomb_len = bomb.size();
        if( res.size() >= bomb_len){
            string target = res.substr(res.size()-bomb_len);
            if(target == bomb) res.erase(res.size() - bomb_len);
        }
        
    }

    if(res.size()) cout << res;
    else cout << "FRULA";

    return 0;
}