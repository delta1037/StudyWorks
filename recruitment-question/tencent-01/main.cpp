#include <iostream>
#include <stack>

using namespace std;

string decodeString(string s) {
    int strLen = s.size();
    int num = 0;
    stack<int> numStack;
    stack<string> strStack;

    string cur = "";
    string ret = "";

    for(int i = 0; i < strLen; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
        }else if(s[i] == '[') {
            continue;
        }else if(s[i] == '|') {
            numStack.push(num);
            strStack.push(cur);
            num = 0;
            cur.clear();
        }else if (s[i] == ']'){
            int k = numStack.top();
            numStack.pop();
            for(int j = 0; j < k; j++){
                strStack.top() += cur;
            }
            cur = strStack.top();
            strStack.pop();
        }else{
            cur += s[i];
        }
    }
    return cur;
}

int main() {
    string testS = "";
    string res = "";
    cin >> testS;
    cout << "input : " + testS << endl;

    res = decodeString(testS);

    cout << res;
    return 0;
}