#include <iostream>

using namespace std;


int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

void printMax(int max(int, int), int a, int b){
    std::cout << (*p)(a,b) <<endl;
}

int main() {
    printMax(max, 1, 2);
    return 0;
}