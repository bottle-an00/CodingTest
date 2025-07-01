#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N{},res{};
    cin >> N;
    vector<bool> is_prime(N+1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i{2}; i*i <= N; ++i){
        if(is_prime[i]){
            for(int j{i*i}; j <= N; j += i){
                is_prime[j] = false;
            }
        }
    }
    
    vector<int> prime_number;
    for (int i{2}; i <= N; ++i){
        if(is_prime[i]) prime_number.push_back(i);
    }

    int l{},r{},sum{};
    while (true) {
        if (sum >= N) sum -= prime_number[l++];
        else if (r == prime_number.size()) break;
        else sum += prime_number[r++];
        
        if (sum == N) res++;
    }

    cout << res;
    return 0;
}