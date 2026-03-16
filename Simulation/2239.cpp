#include <iostream>
#include <vector>
using namespace std;

int db[9][9], col[9], row[9], box[3][3];
vector<pair<int, int>> blank;

int get_available(int i, int j){
    return ~(col[j] | row[i] | box[i/3][j/3]) & ((1 << 10) - 2);
}

bool dfs(int idx){

    if(idx == blank.size())
        return true;

    int x = blank[idx].first;
    int y = blank[idx].second;

    int state = get_available(x, y);

    while(state){

        int bit = state & -state;
        state -= bit;

        int num = 0;
        for(int i = 1; i <= 9; i++){
            if(bit == (1 << i)){
                num = i;
                break;
            }
        }

        db[x][y] = num;

        row[x] |= bit;
        col[y] |= bit;
        box[x/3][y/3] |= bit;

        if(dfs(idx+1))
            return true;

        row[x] ^= bit;
        col[y] ^= bit;
        box[x/3][y/3] ^= bit;
    }

    return false;
}

int main(){

    fill(&col[0], &col[0]+9, 0);
    fill(&row[0], &row[0]+9, 0);
    fill(&box[0][0], &box[0][0]+9, 0);

    for(int i{}; i < 9; ++i){
        string line;
        cin >> line;

        for(int j{}; j < 9; ++j){
            db[i][j] = line[j] - '0';

            if(db[i][j] != 0){
                int num = db[i][j];
                col[j] |= (1 << num);
                row[i] |= (1 << num);
                box[i/3][j/3] |= (1 << num);
            } else {
                blank.push_back({i, j});
            }
        }
    }

    dfs(0);

    for(int i{}; i < 9; ++i){
        for(int j{}; j < 9; ++j){
            cout << db[i][j];
        }
        cout << '\n';
    }
    return 0;
}