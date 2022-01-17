#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int maxLength(vector<pair<int, int>> &XH) {
    sort(XH.begin(), XH.end(), cmp);
    int res = 1;

    for(int i = 1; i < XH.size(); ++i){
        if(XH[i].first >= XH[i-1].first && XH[i].second >= XH[i-1].second){
            res++;
        }
    }

    return res;
}

int main() {
    int arrSize = 0,tmp1, tmp2;
    cin >> arrSize;

    vector<pair<int, int>> XH(arrSize, pair<int, int>(0, 0));

    for(int i = 0; i < arrSize; ++i){
        cin >> tmp1 >> tmp2;
        XH[i].first = tmp1;
        XH[i].second = tmp2;
    }
    cout << maxLength(XH);
    return 0;
}
/*
4
3 2
1 1
1 3
2 2

3
 */