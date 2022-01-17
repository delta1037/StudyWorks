#include <iostream>

using namespace std;

int caNum(string &str){
    int res = 0;

    int first_index = -1;
    int last_index = -1;
    bool hasStr = false;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ','){
            // update res
            if(first_index != last_index && hasStr){
                res++;
            }
            if(str[i+1] >= '0' && str[i+1] <= '9'){
                first_index = i+1;
                last_index = i+1;
            }else{
                first_index = -1;
                last_index = -1;
            }
            hasStr = false;
        }else if(str[i] >= '0' && str[i] <= '9'){
            if(hasStr && (i == str.size() - 1 || str[i+1] == ',')){
                last_index = i;

                if(i == str.size() - 1){
                    res++;
                }
            }
        }else{
            hasStr = first_index != -1;
        }
    }

    return res;
}

int main() {
    string str = "hello,78,9,1.9,999";
    //cin >> str;
    //
    cout << caNum(str);

    return 0;
}