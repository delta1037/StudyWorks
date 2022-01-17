#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool set_eq(const multiset<int> &a, const multiset<int> &b){

    for(auto a1 = a.begin(), b1 = b.begin(); a1 != a.end(); ++a1, ++b1){
        if(*a1 != *b1){
            return false;
        }
    }
    return true;
}

int minGroup(vector<int> &nums){
    int res = 0;
    vector<int> sort_nums = nums;
    sort(sort_nums.begin(), sort_nums.end());
    multiset<int> sort_tmp, tmp;

    for(int i = 0; i < nums.size(); i++){
        sort_tmp.insert(sort_nums[i]);
        tmp.insert(nums[i]);

        if(set_eq(sort_tmp, tmp)){
            sort_tmp.clear();
            tmp.clear();
            ++res;
        }
    }

    return res;
}

int main() {
    int std_nums = 0;
    cin >> std_nums;
    vector<int> num(std_nums, 0);
    for(int i = 0; i < std_nums; i++){
        cin >> num[i];
    }

    cout << minGroup(num);

    return 0;
}