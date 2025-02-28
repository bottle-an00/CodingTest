#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> T;
vector<int> input;
int k;
void solve_9934(int l, int r, int level){
    if(l > r) return;
    if(l == r){
        T[level].push_back(input[l]);
        return;
    }

    int mid = (l + r) / 2;
    T[level].push_back(input[mid]);
    solve_9934(l,mid-1,level+1);
    solve_9934(mid+1,r,level+1);
}
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
    solve_9934(0,input.size()-1, 0);
    for(int i = 0; i < k; ++i){
        for(auto e : T[i]){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
