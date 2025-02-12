#include <iostream>
using namespace std;
#define R 1
#define L 0
int basket_size{0};
bool is_possible(int apple_position, int current_basket_position){
    int distance = apple_position - current_basket_position;
    return distance <= basket_size && distance > 0;
}
int direction(int apple_position, int current_basket_position){
    return (apple_position - current_basket_position > 0) ? 1 : 0;
}
int solve_2828(int apple_position, int& current_basket_position){
    if (is_possible(apple_position, current_basket_position)) {
        return 0;
    }

    int move_distance = 0;
    if (direction(apple_position, current_basket_position) == R) { // 오른쪽 이동
        move_distance = apple_position - (current_basket_position + basket_size);
        current_basket_position += move_distance;
    } else { // 왼쪽 이동
        move_distance = current_basket_position - apple_position;
        current_basket_position -= move_distance;
    }
    
    return move_distance;
}
int main(){
    int N, M;
    cin >> N >> M;
    basket_size = M -1;
    int apple_count{1}, result{0},current_basket_position{1};
    cin >> apple_count;
    cin.ignore();
    for(int i = 0; i < apple_count; ++i){
        cout << "current b_c : " << current_basket_position << endl;
        int position;
        cin >> position;
        result += solve_2828(position, current_basket_position);
    }

    cout << result;
    return 0;
}