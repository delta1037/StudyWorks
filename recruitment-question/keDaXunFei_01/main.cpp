#include <iostream>
#include <vector>

using namespace std;

void recur(vector<int> &box, vector<int> &add, int box_index, int box_size){

}


int main() {
    int box_num = 0;
    cin >> box_num;

    int last_num = 0;
    cin >> last_num;

    vector<int> box(box_num, last_num);
    vector<int> add(box_num, 0);

    int sum = recur(box, add, 0, box.size());

    return 0;
}