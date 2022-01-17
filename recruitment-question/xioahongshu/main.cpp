#include <iostream>
#include <vector>

using namespace std;

int redCircleNum(vector<vector<int>> &userMap){
    int res = 0;
    int userSize = userMap.size();
    // 标记所有用户均可以被添加到一个红圈中
    vector<bool> userAdd(userSize, true);

    for(int i = 0; i < userSize; ++i){
        // 定义一个红圈，准备向该圈中添加一组用户
        vector<int> oneRedCircle;

        // find the first user not circle
        if(userAdd[i]){
            userAdd[i] = false;
            oneRedCircle.push_back(i);

            // add all the user who know this user
            for(int j = 1; j < userSize; ++j){
                if(userMap[i][j] == 1 && userAdd[j]){
                    oneRedCircle.push_back(j);
                    userAdd[j] = false;
                }
            }

            // user queue to add other user who know this group
            int oneCircleUserSize = oneRedCircle.size();
            if(oneCircleUserSize > 1){
                for(int j = 1; j < oneCircleUserSize; ++j){
                    for(int k = 0; k < userSize; ++k){
                        if(userMap[oneRedCircle[j]][k] == 1 && userAdd[k]){
                            oneRedCircle.push_back(k);
                            oneCircleUserSize++;
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
    int userSize = 0;
    cin >> userSize;

    vector<vector<int>> user(userSize, vector<int>(userSize, 0));

    for(int i = 0; i < userSize; ++i){
        for(int j = 0; j < userSize; ++j){
            cin >> user[i][j];
        }
    }

    cout << redCircleNum(user);
    return 0;
}