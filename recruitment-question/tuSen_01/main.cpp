#include <iostream>
#include <vector>

using namespace std;

bool match(vector<vector<int>> &matrix, int row, int col){
    bool res = false;

    if(matrix[row-1][col] == 1
        && matrix[row][col-1] == 1
        && matrix[row+1][col] == 1
        && matrix[row][col+1] == 1){
        res = true;
    }

    return res;
}
int Solution(vector<vector<int>> &matrix){
    int res = 0;
    if(matrix.empty()){
        return res;
    }

    int row = matrix.size(), col = matrix[0].size();
    if(row < 3 || col < 3){
        return res;
    }

    for(int i = 1; i < row - 1; ++i){
        for(int j = 1; j < col - 1; ++j){
            if(matrix[i][j] == 1 && match(matrix, i, j)){
                ++res;
            }
        }
    }

    return res;
}
int main() {
    int m = 0, n = 0, tmp;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }

    cout << Solution(matrix);
    return 0;
}