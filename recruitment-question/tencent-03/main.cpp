#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &odd1,const vector<int> &odd2){
    if(odd1[0] != odd2[0]){
        return odd1[0] < odd2[0];
    }else{
        return odd1[1] > odd2[1];
    }
}

int minNum(vector<vector<int>> &array, int L){
    int res = 1;
    int max = -1;
    int maxIndex = -1;
    int lastTail = array[0][1];

    for(int i = 1; i < array.size(); i++){
        if(array[i][0] == array[i-1][0]){
            continue;
        }
        if(array[i][0] <= lastTail){
            if(array[i][1] > max){
                maxIndex = i;
                max = array[i][1];
            }
        }else{
            res++;
            lastTail = array[maxIndex][1];

            if(lastTail >= L){
                break;
            }

            max = array[i][1];
            maxIndex = i;
        }

        if(i == array.size() -1){
            res++;
        }
    }

    return res;
}
int main() {
    int nums, L;
    cin >> nums >> L;

    vector<vector<int>> array(nums, vector<int>(2, 0));
    for(int i = 0; i < nums; i++){
        cin >> array[i][0] >> array[i][1];
    }

    sort(array.begin(), array.end(), compare);

    if(array[0][0] != 0 || array[array.size()-1][1] < L){
        cout << -1;
    }else{
        cout << minNum(array, L);
    }
    return 0;
}
