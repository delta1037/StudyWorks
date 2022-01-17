#include <iostream>
#include <vector>

using namespace std;

int beanNum(vector<vector<int>> &userMap){
    int res = 0;
    int userSize = userMap.size();
    vector<bool> userAdd(userSize, true);

    for(int i = 0; i < userSize; ++i){
        vector<int> bootle;

        if(userAdd[i]){
            userAdd[i] = false;
            bootle.push_back(i);

            for(int j = 1; j < userSize; ++j){
                if(userMap[i][j] >= 3 && userAdd[j]){
                    bootle.push_back(j);
                    userAdd[j] = false;
                }
            }

            int bootleSize = bootle.size();
            if(bootleSize > 1){
                for(int j = 1; j < bootleSize; ++j){
                    for(int k = 0; k < userSize; ++k){
                        if(userMap[bootle[j]][k] >= 3 && userAdd[k]){
                            bootle.push_back(k);
                            bootleSize++;
                            userAdd[k] = false;
                        }
                    }
                }
            }
            ++res;
        }
    }

    return res;
}

int main() {
    int arrSize = 0;
    cin >> arrSize;

    vector<vector<int>> arr(arrSize, vector<int>(arrSize, 0));

    for(int i = 0; i < arrSize; ++i){
        for(int j = 0; j < arrSize; ++j){
            cin >> arr[i][j];
        }
    }

    cout << beanNum(arr);
    return 0;
}