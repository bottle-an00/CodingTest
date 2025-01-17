#include <bits/stdc++.h>

using namespace std;

void solve(int* input){
    int sum{};
    for(int i =0; i < 7; ++i){
        sum += input[i]; 
    }

    if(sum == 100){
        sort(input,input+7);
        for(int i = 0; i < 7; ++i) cout <<input[i] << endl; 
        exit(0);
    }
}

void makePermutation(int* input, int n, int r, int depth){
    if(r == depth){
        solve(input);
    }

    for(int i = depth; i < n; ++i){
        swap(input[i],input[depth]);
        makePermutation(input,n,r,depth+1);
        swap(input[i],input[depth]);
    }

}

int main(){
    int nanjangs[9];
    for(int i = 0; i < 9; ++i){
        cin >> nanjangs[i];
    } 

    makePermutation(nanjangs,9,7,0);
    
    return 0;
}