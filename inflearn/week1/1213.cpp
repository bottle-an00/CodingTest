#include <bits/stdc++.h>
using namespace std;

void add_char2string(int weight, string& res, char input){
    for(int i =0; i < weight; ++i){
        res += input;
    }
}

int main(){
    string input_str;
    cin >> input_str;

    map<char,int> mp;
    for(int i = 0; i < (int)input_str.size(); ++i){
        if(mp.find(input_str[i]) != mp.end()) 
            ++mp[input_str[i]];
        else 
            mp[input_str[i]] = 1;
    }

    int cnt{};
    for(auto iter = mp.begin(); iter!=mp.end(); ++iter){
        if(iter->second%2) ++cnt;
    }

    if(cnt > 1){
        cout <<  "I'm Sorry Hansoo" << endl;
    }else{
        string res;
        char middle;
        for(auto iter = mp.begin(); iter!= mp.end(); ++iter){
            if(iter->second % 2) {
                middle = iter->first;
                if(iter->second > 1) add_char2string(iter->second/2,res,iter->first);
            }else{
                add_char2string(iter->second/2,res,iter->first);
            }
        }
        string tmp = res;
        reverse(tmp.begin(),tmp.end());
        if (cnt == 1) {  
            res = res + middle + tmp;
        } else {
            res = res + tmp;
        }
        cout << res << endl;
    }
    return 0;
}