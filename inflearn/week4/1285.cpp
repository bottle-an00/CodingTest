#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

int N{},min_sum{INT_MAX};
vector<vector<int>> input_bit;

int count_backside(int data){
    int count{};
    while(1){
        if(data & -data) count++;
        else break;
    }
    return count;
}

bool is_valid(int data){return count_backside(data) ? true: false;}

int cal_sum(vector<int> data)
{
    int sum{};
    for(int i = 0; i< N; ++i){
        sum += count_backside(data[i]);
    }
    return sum;
}

void solve_1285(vector<vector<int>> data)
{
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < N; ++j){
            if(is_valid(data[0][j])) 
            {
                vector<vector<int>> tmp = data;
                tmp[0][j] = ~tmp[0][j];
                tmp[1][j] = ~tmp[1][j];
                solve_1285(tmp);
            }
        }
    }
    min_sum = min(min_sum,cal_sum(data[0]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin.ignore();
    char buf[2][N][N];
    input_bit.assign(N,vector<int>(N,-1));
    for(int i = 0; i < N; ++i){
        string input_str;
        getline(cin,input_str);
        for(int j = 0; j < N; ++j){
            char e = (input_str[j] == 'H'? '1' : '0');
            buf[0][i][j] = e;
            buf[1][j][i] = e;
            cout << e << endl;
        }
    }
    for(int i = 0; i < N; ++i){
        string tmp[2];
        for(int j = 0; j < N; ++j){
            tmp[0] += buf[0][i][j];
            tmp[1] += buf[1][i][j];
       }
       cout << stoi(tmp[0],nullptr,2) << endl;
       input_bit[0][i] = stoi(tmp[0],nullptr,2);
       input_bit[1][i] = stoi(tmp[1],nullptr,2);
    }
    solve_1285(input_bit);
    cout << min_sum;
    return 0;

}