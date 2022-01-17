#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

void countNum(vector<int> & array){
    vector<int> front(array.size(), 0);
    vector<int> back(array.size(), 0);

    stack<int> sta_front;
    stack<int> sta_back;

    sta_front.push(array[0]);
    for(int i = 1; i  < array.size(); i++){
        front[i] = sta_front.size();

        while(!sta_front.empty() && array[i] >= sta_front.top()){
            sta_front.pop();
        }

        sta_front.push(array[i]);
    }

    sta_back.push(array[array.size() - 1]);
    for (int i = array.size() - 2; i >= 0 ; --i) {
        back[i] = sta_back.size();

        while(!sta_back.empty() && array[i] >= sta_back.top()){
            sta_back.pop();
        }

        sta_back.push(array[i]);
    }

    for(int i = 0; i < array.size(); i++){
        cout << front[i] + back[i] + 1;
        if(i != array.size() - 1){
            cout << " ";
        }
    }
}

int main() {
    int num = 0;
    cin >> num;
    vector<int> A(num, 0);

    for(int i = 0; i < num; i++){
        cin >> A[i];
    }

    countNum(A);
    return 0;
}
//c 6
//5 3 8 3 2 5
// 3 3 5 4 4 4