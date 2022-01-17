#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    Solution(int n){
        dp = vector<int>(n + 1, -1);
        dp[0] = 0;
        dp[2] = 1;
        dp[4] = 2;
        dp[6] = 5;
    }
    int allNum(int n){
        if(dp[n] > -1){
            return dp[n];
        }

        dp[n] = 0;
        for(int i = 1; i <= n / 2; i += 2){
            if(i <= 3 || i == n/2){
                dp[n] += 2 * allNum(n - 1 - i);
            }else{
                dp[n] += 2 * allNum(n - 1 - i) + 2 * allNum(i - 1);
            }
        }

        return dp[n];
    }

    int Catalan(int n){
        vector<vector<int>> catalan(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            catalan[0][i] = 1;
        }
        for(int i = 1; i < n; ++i){
            catalan[i][i] = catalan[i-1][i];
            for(int j = i + 1; j < n; ++j){
                catalan[i][j] = catalan[i-1][j] + catalan[i][j-1];
            }
        }

        return catalan[n-1][n-1];
    }
    /*
     * 6
     * 0 1 2 3 4 5
     *
     */
    /*
     * 8
     * 0 1 2 3 4 5 6 7
     * 0-1 dp[6]
     * 0-7 dp[6]
     *
     * 0-3 dp[4]
     * 0-5 dp[4]
     */
    /*
     * 10
     * 0 1 2 3 4 5 6 7 8 9
     * 0-1 dp[8]
     * 0-9 dp[8]
     *
     * 0-3 dp[6]
     * 0-7 dp[6]
     *
     * 0-5 dp[4]
     * 0-5 dp[4]
     *
     */

    /*
     * 12
     * 0 1 2 3 4 5 6 7 8 9 10 11
     * 0-1 dp[10]
     * 0-11 dp[10]
     *
     * 0-3 dp[8]
     * 0-9 dp[8]
     *
     * 0-5 dp[4] + dp[6]
     * 0-7 dp[4] + dp[6]
     */

private:
    vector<int> dp;
};

int main() {
    int n = 0;
    cin >> n;

    Solution s(n);
    cout << s.Catalan(n/2 + 1);

    // h(n)=h(n-1)*(4*n-2)/(n+1);

    return 0;
}