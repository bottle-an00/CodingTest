#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int N;
    cin >> N; 

    for(int i = 0; i <N; ++i){
        int M;
        cin >> M;
        cin.ignore();
        map<string,vector<string>> mp;
        for(int j = 0 ; j < M; ++j){
            string input;
            getline(cin,input);

            auto pos = input.find(" ");
            string name = input.substr(0,pos);
            string category = input.substr(pos+1,input.size());

            mp[category].push_back(name);
        }

        int res{1};
        for(auto iter = mp.begin(); iter !=mp.end(); ++iter){
            res *= iter->second.size() + 1;
        }
        cout << --res << endl;
    }

    return 0;
}