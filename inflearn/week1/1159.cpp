#include <bits/stdc++.h>
using namespace std;

int main(){
    int N{};
    cin >> N;

    vector<int> players('z' - 'a' + 1,0);
    for(int i=0; i < N; ++i){
        string first_name;
        cin >> first_name;
        ++players[first_name[0] - 'a']; 
    }

    string res;
    for(int i = 0; i <= 'z' -'a'; ++i){
        if(players[i] >= 5) {
            res += (static_cast<char>(i + 'a'));
        }
    }

    if(res.size() == 0) cout << "PREDAJA";
    else cout << res;

    return 0;
}