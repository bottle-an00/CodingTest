#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nanjangs(9);
    for(int i = 0; i < 9; ++i){
        cin >> nanjangs[i];
    } 

    sort(nanjangs.begin(), nanjangs.end());    
    do{ 
        int sum{};
        for(int i = 0; i < 7; ++i) sum += nanjangs[i];
        
        if(sum == 100) break;
    }while(next_permutation(nanjangs.begin(), nanjangs.end()));
    
    for(int nanjang = 0; nanjang < 7; ++nanjang){cout << nanjangs[nanjang] << endl;}

    return 0;
}