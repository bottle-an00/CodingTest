#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int N{};
    long long C{};
    cin >> N >> C;
    
    unordered_map<long long, int> mapDB;
    vector<long long> order; 

    for(int i = 0; i < N; ++i){
        long long input;
        cin >> input;
        if(mapDB[input]++ == 0){ 
            order.push_back(input);
        }
    }

    stable_sort(order.begin(), order.end(), [&](long long a, long long b) {
        return mapDB[a] > mapDB[b];
    });

    for(long long num : order){
        for(int j = 0; j < mapDB[num]; ++j){
            cout << num << ' ';
        }
    }

    return 0;
}
