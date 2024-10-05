#include <iostream>
using namespace std;

int add_nums(int a, int b){
    if (a < 0 || b < 0)
        return 0;
    else
        return a+b;
}
int main(){

    int q=-1, w=2;
    cout << add_nums(q,w);

    return 0;
}