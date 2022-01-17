#include <iostream>
#include <vector>

using namespace std;

const int matrixNum = 4;
/*
1
0 2 2 4
2 4 2 2
2 4 2 4
0 8 2 4
 */


void upMerge(vector<vector<int>> &matrix){
    for(int col = 0; col < matrixNum; ++col){
        int mergeSite = 0;
        for(int row = 0; row < matrixNum - 1; ++row){
            if(matrix[row][col] == 0){
                continue;
            }else{
                if(matrix[row][col] == matrix[row+1][col]){
                    matrix[mergeSite][col] = matrix[row][col] * 2;
                    ++row;
                    ++mergeSite;
                }
            }
        }

        for(int i = mergeSite; i < matrixNum - 1; i++){
            matrix[i][col] = 0;
        }
    }
}

void downMerge(vector<vector<int>> &matrix){
    for(int col = 0; col < matrixNum; ++col){
        int mergeSite = 3;
        for(int row = matrixNum - 2; row >= 0; --row){
            if(matrix[row][col] != 0 && matrix[row-1][col] == matrix[row][col]){

                matrix[mergeSite][col] = matrix[row][col] * 2;
                --row;
            }
            --mergeSite;
        }

        for(int i = mergeSite; i > 0; i--){
            matrix[i][col] = 0;
        }
    }
}

void mergeMatrix(vector<vector<int>> &matrix, int vec){
    if(vec == 1){
        upMerge(matrix);
    }else if(vec == 2){
        downMerge(matrix);
    }
}


int main() {
    vector<vector<int>> matrix(matrixNum, vector<int>(matrixNum, 0));
    int vec = 0;
    cin >> vec;

    for(int i = 0; i < matrixNum; ++i){
        for(int j = 0; j < matrixNum; ++j){
            cin >> matrix[i][j];
        }
    }

    mergeMatrix(matrix, vec);

    for(int i = 0; i < matrixNum; ++i){
        for(int j = 0; j < matrixNum - 1; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << matrix[i][3] <<endl;
    }

    return 0;
}
