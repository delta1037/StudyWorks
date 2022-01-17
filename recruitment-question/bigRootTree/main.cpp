#include <iostream>
#include <vector>

using namespace std;

// left mid right

int slideWindow(vector<bool> &drinkCoffee, int tab){
    int res = 0;

    if(tab == 0){
        return 30;
    }

    int drinkNums = 0;
    int mid = 0, left, right;

    left = mid-2 >= 0? mid-2:0;
    right = mid+2 < drinkCoffee.size()? mid+2:drinkCoffee.size()-1;

    for(int i = left; i < right; ++i){
        if(drinkCoffee[i]){
            drinkNums++;
        }
    }

    for(int i = 0; i < drinkCoffee.size(); ++i){
        if(drinkCoffee[i]){
            res++;
        }
    }

    return res;
}

int main() {
    vector<int> drinkDay = {5, 9, 13, 14, 21, 25, 29};
    vector<bool> drinkCoffee(30, false);

    for(int i = 0; i < drinkDay.size(); ++i){
        drinkCoffee[drinkDay[i]] = true;
    }

    slideWindow(drinkCoffee, 1);
    return 0;
}