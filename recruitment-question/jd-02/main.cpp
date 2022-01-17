#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
public:
    void myBreakFriend(vector<vector<bool>> &stu_map, vector<int> &stu_b_num, vector<int> &stu_g_num, int b_num, int g_num){
        int b_max_index = 0, g_max_index = 0;
        int n = stu_b_num.size();
        minNum = 0;
        while(b_num != 0 && g_num != 0){
            b_max_index = 0;
            for(int i = 0 ; i < n; ++i){
                if(stu_b_num[i] > stu_b_num[b_max_index]){
                    b_max_index = i;
                }
            }

            g_max_index = 0;
            for(int i = 0 ; i < n; ++i){
                if(stu_g_num[i] > stu_g_num[g_max_index]){
                    g_max_index = i;
                }
            }

            if(stu_b_num[b_max_index] > stu_g_num[g_max_index]){
                stu_b_num[b_max_index] = 0;
                for(int i = 0; i < n; ++i){
                    if(stu_map[b_max_index][i]){
                        stu_map[b_max_index][i] = false;
                        --stu_g_num[i];
                        --b_num;
                        --g_num;
                    }
                }
                minNum++;
                number.push_back(b_max_index);
            }else{
                stu_g_num[g_max_index] = 0;
                for(int i = 0; i < n; ++i){
                    if(stu_map[i][g_max_index]){
                        stu_map[i][g_max_index] = false;
                        --stu_b_num[i];
                        --b_num;
                        --g_num;
                    }
                }
                minNum++;
                number.push_back(g_max_index + n);
            }
        }
    }

    void printResult(){
        cout << minNum << endl;
        for(int i = 0; i < minNum - 1; ++i){
            cout << number[i] << ' ';
        }
        cout <<  number[minNum - 1];
    }

private:
    int minNum;
    vector<int> number;
};


int main() {
    int stu_num = 0, m_num = 0;

    cin >> stu_num;
    cin >> m_num;

    vector<vector<bool>> stu_m(stu_num + 1, vector<bool>(stu_num + 1, false));
    vector<int> stu_b_num(stu_num + 1, 0);
    vector<int> stu_g_num(stu_num + 1, 0);

    int g_num = 0, b_num = 0;

    int t_stu_g, t_stu_b;
    for(int i = 0; i < m_num; i++){
        cin >> t_stu_b >> t_stu_g;
        stu_m[t_stu_b][t_stu_g - stu_num] = true;
        ++stu_b_num[t_stu_b];
        ++stu_g_num[t_stu_g - stu_num];

        ++g_num;
        ++b_num;
    }

    Solution s;
    s.myBreakFriend(stu_m, stu_b_num, stu_g_num, b_num, g_num);
    s.printResult();

    return 0;
}