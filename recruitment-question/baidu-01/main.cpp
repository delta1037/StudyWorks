#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }

    static bool cmp2(const vector<int> &a, const vector<int> &b){
        return a.size() > b.size();
    }

    vector<int> combinationSum(vector<pair<int, int>> &candidates, int target) {
        vector<vector<int>> results{};
        vector<int> result{};
        sort(candidates.begin(), candidates.end(), cmp);
        dfs(results, result, candidates, target, 0);

        sort(results.begin(), results.end(), cmp2);

        vector<vector<int>> allRes{};

        allRes.push_back(results[0]);
        int needSize = results[0].size();
        for(int i = 1; i < results.size(); ++i){
            if(results[i].size() == needSize){
                allRes.push_back(results[i]);
            }else{
                break;
            }
        }

        if(allRes.size() == 1){
            sort(allRes[0].begin(), allRes[0].end(), greater<int>());
            return allRes[0];
        }else{
            for(int i = 0; i < allRes.size(); ++i){
                sort(allRes[i].begin(), allRes[i].end(), greater<int>());
            }

            int width = allRes.size() - 1;
            int idx = 0;

            while (width != 1 && idx < allRes[0].size()){

            }
        }

        return results[0];
    }

    void dfs(vector<vector<int>>& results, vector<int>& result, vector<pair<int, int>>& candidates, int target, int level){
        if(target == 0){
            results.push_back(result);
            return;
        }

        for(int i=level; i < candidates.size() && target - candidates[i].second >= 0; i++){
            result.push_back(candidates[i].second);
            dfs(results, result, candidates, target - candidates[i].second, i);
            result.pop_back();
        }
    }
};

int main() {
    int n = 0, m = 0;
    cin >> n;
    cin >> m;
    vector<pair<int, int>> nums(m);
    vector<int> map = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for(int i = 0; i < m; ++i){
        int tmp = 0;
        cin >> tmp;
        nums[i].first  = tmp;
        nums[i].second = map[tmp];
    }

    cout << maxNum(nums, n);

    return 0;
}