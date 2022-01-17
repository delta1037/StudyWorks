#include <iostream>
#include <vector>

using namespace std;


string getNote(string &input){
    string res;
    vector<char> brackets;


    for(char i : input){
        if(i == '('){
            brackets.push_back('(');
            continue;
        }else if(i == ')'){
            brackets.pop_back();
            continue;
        }
        if(brackets.empty()){
            if(i == '<' && !res.empty()){
                res.pop_back();
            }else if(i != '<'){
                res.push_back(i);
            }
        }
    }
    return res;
}


string getNote_01(string &input){
    string notes;
    stack<char> sta;

    for(int i = 0; i < input.size(); ++i){
        if(input[i] == '('){
            sta.push('(');
            continue;
        }else if(input[i] == ')'){
            sta.pop();
            continue;
        }
        if(sta.empty()){
            if(input[i] == '<' && !notes.empty()){
                notes.pop_back();
            }else if(input[i] != '<'){
                notes.push_back(i);
            }
        }
    }

    return notes;
}

int main() {
    string input;
    cin >> input;

    cout << getNote(input);

    return 0;
}