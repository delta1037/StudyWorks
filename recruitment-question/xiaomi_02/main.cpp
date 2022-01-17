#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solution(vector < int > arr) {
    int arrLen = arr.size();
    if (arrLen < 3) {
        return 0;
    }

    int max_len = 0;
    vector<int> dp1(arrLen, 1);
    vector<int> dp2(arrLen, 1);
    for (int i = 1; i < arrLen; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
            if (arr[i] <= arr[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    max_len = dp1[0];
    for (int k = 1; k < arrLen; ++k) {
        max_len = max(max(max_len, dp1[k]), dp2[k]);
    }
    return arrLen-max_len;
}
/******************************结束写代码******************************/


int main() {
    int res;

    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _arr;
    int _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        cin >> _arr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }

    res = solution(_arr);
    cout << res << endl;

    return 0;

}