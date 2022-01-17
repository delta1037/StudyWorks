#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/

void moveOneLine(vector<int> &line){
    for(int i = 1, k = 0; i < line.size(); ++i){
        if(line[i] > 0){
            if(line[k] == line[i]){
                line[k++]  *= 2;
                line[i] = 0;
            }else if(line[k] == 0){
                line[k] = line[i];
                line[i] = 0;
            }else{
                ++k;
                line[k] = line[i];

                if(k != i){
                    line[i] = 0;
                }
            }
        }
    }
}

void solution(vector<vector<int>> &input) {
    for(int i = 0; i < input.size(); ++i){
        moveOneLine(input[i]);
    }
}
/******************************结束写代码******************************/

int main() {

    //string res;

    int _input_size = 0;
    cin >> _input_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _input;
    string _input_item;
    for(int _input_i=0; _input_i<_input_size; _input_i++) {
        getline(cin, _input_item);
        _input.push_back(_input_item);
    }

    vector<vector<int>> input(_input_size);

    int val = 0;
    for(int i = 0; i < _input_size; ++i){
        for(int j = 0; j < _input[i].size(); ++j){
            if(_input[i][j] == ' '){
                input[i].push_back(val);
                val = 0;
            }else{
                val = val * 10 + _input[i][j] - '0';
                if(j == _input[i].size() - 1){
                    input[i].push_back(val);
                    val = 0;
                }
            }
        }
    }

    solution(input);
    //cout << res << endl;

    for(int i = 0; i < _input_size; ++i){
        for(int j = 0; j < input[i].size() - 1; j++){
            cout << input[i][j] << " ";
        }
        cout << input[i][input[i].size() - 1] << endl;
    }

    return 0;

}
