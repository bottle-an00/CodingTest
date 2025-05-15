#include <iostream>
using namespace std;
int solve_1094(int X){
    int count{};
    for(int i = 0; i < 7; ++i){
        if(X & (1 << i)) ++count;
    }
    return count;
}

int main(){
    int X ={};
    cin >> X;
    cout << solve_1094(X);
    return 0;
}