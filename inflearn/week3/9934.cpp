#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> T;
vector<int> input;
int k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    T.assign(k,vector<int>());
    for(int i = 0; i < pow(2,k) -1; ++i){
        int node;
        cin >> node;
        input.push_back(node);
    }
    if(k == 1) {cout << input[0]<<"\n"; return 0;}

    int idx = 1;
    for(int i = 0; i < k; ++i){
        --idx;
        int swift = idx;
        while(swift <= input.size()){
            T[i].push_back(input[swift]);
            swift += pow(2,i+1);
        }
        idx = (idx+1)*2;
    }
    for(int i = k-1; i >= 0; --i){
        for(auto e : T[i]){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
