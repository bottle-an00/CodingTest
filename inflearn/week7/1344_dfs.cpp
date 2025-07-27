#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
double pA, pB,dp[20][20][20];

bool is_prime[20];
const int stepA[4] = {0,0,1,1};
const int stepB[4] = {0,1,0,1};

void make_prime_table(){
    fill(is_prime, is_prime + 20, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < 20; ++i){
        if(is_prime[i]){
            for(int j = i * i; j < 20; j += i){
                is_prime[j] = false;
            }
        }
    }
}

double dfs(int cnt,int sA, int sB){
    if(cnt == 18){
        if(is_prime[sA] || is_prime[sB]) return 1;
        else return 0;
    }

    double &ret = dp[cnt][sA][sB]; 
    if(ret > -0.5) return ret; 

    ret = 0.0; 
    for(int i{}; i < 4; ++i){
        ret += dfs(cnt+1,sA+stepA[i],sB+stepB[i])*(stepA[i] ? pA : (1-pA))*(stepB[i] ? pB : (1-pB));
    }

    return ret;
}

int main(){
    cin >> pA >> pB;
    pA /= 100;
    pB /= 100;

    make_prime_table();

    memset(dp, -1, sizeof(dp));

    cout << setprecision(16) << dfs(0,0,0);
    return 0;
}