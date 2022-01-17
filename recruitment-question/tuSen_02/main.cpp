#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <climits>

using namespace std;
bool isPrime_yu(int num){
    if (num <= 3) {
        return num > 1;
    }

    for(int i = 2; i < num >> 1; ++i){
        if(num%i){
            return false;
        }
    }
    return true;
}
bool isPrime(int num){
    if (num <= 3) {
        return num > 1;
    }

    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }

    int sqrt_num = (int)sqrt(num);
    for (int i = 5; i <= sqrt_num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// str1 ==> str2
int Solution(string str1, string str2, set<int> &notSame){
    int res = INT_MAX;
    if(notSame.size() == 1){
        return 1;
    }
    for(auto it = notSame.begin(); it != notSame.end(); it++){
        swap(str1[*it], str2[*it]);
        if(isPrime_yu(stoi(str1))){
            notSame.erase(*it);
            res = min(res, Solution(str1, str2, notSame) + 1);
            notSame.insert(*it);
        }
        swap(str1[*it], str2[*it]);
    }

    return res;
}


int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    set<int> notSameSet;

    for(int i = 0; i < str1.size(); ++i){
        if(str1[i] != str2[i]){
            notSameSet.insert(i);
        }
    }
    cout << Solution(str1, str2, notSameSet);

    return 0;
}