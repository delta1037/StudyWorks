#include <iostream>
#include <vector>

using namespace std;

void reverse(int s, int e, vector<int> & numsArray){
    while(s < e){
        swap(numsArray[s], numsArray[e]);
        s++;
        e--;
    }
}

int reversePairNum(int pair, vector<int> & numsArray){
    int res = 0;
    int numsSize = numsArray.size();

    for(int i = 0; i < numsSize; i += pair){
        reverse(i, i + pair - 1, numsArray);
    }

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(numsArray[j] < numsArray[i]){
                res++;
            }
        }
    }

    return res;
}

int main() {
    int n = 0;
    int nums = 0;
    int m = 0;

    cin >> n;
    nums = 1 << n;
    vector<int> numsArray(nums, 0);
    for(int i = 0; i < nums; i++) {
        cin >> numsArray[i];
    }

    cin >> m;
    vector<int> reversePair(m, 0);
    vector<int> tempRes(m, 0);

    int temp = 0;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        reversePair[i] = 1 << temp;

        if(i > 0 && reversePair[i] == 1){
            tempRes[i] = tempRes[i-1];
        }else{
            tempRes[i] = reversePairNum(reversePair[i], numsArray);
        }

        cout << tempRes[i] <<endl;
    }

    return 0;
}
