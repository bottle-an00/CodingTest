#include <iostream>
using namespace std;
using ll = long long;

ll mod_exp(ll A, ll B, ll C){
    if(B == 1) return A % C;
    else{
        ll ret = mod_exp(A,B/2,C);
        ret = (ret*ret)%C;  
        if(B%2)ret = (ret*A)%C;
        return ret;
    }
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    
    cout << mod_exp(A, B, C) << endl;
    
    return 0;
}
