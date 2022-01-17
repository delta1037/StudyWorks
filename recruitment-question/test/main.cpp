#include <iostream>
#include <stack>

using namespace std;

int idx = 1;

void inorderPrint(string &str){
    stack<int> sta;
    if(str.empty()){
        return;
    }
    sta.push(0);
    while(idx < str.size()){
        if(str[idx] >= '0' && str[idx] <= '9'){
            sta.push(idx);
        }else if(str[idx] == '('){
            if(str[idx+1] == ','){

            }
        }else if(str[idx] == ')'){

        }else if(str[idx] == ','){
            sta.pop();
            sta.pop();
        }
        ++idx;
    }

    while(!sta.empty()){
        cout << str[sta.top()];
        sta.pop();
    }
}


int main() {
    string str = "1(2(3,4(,5)),6(7,))";
    inorderPrint(str);
    return 0;
}