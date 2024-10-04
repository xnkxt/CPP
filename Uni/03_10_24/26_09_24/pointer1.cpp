#include <iostream>
using namespace std;

void func(int &x){
    x++;
    cout << x;
}
int main(){
    int a = 1;
    func(a);
    cout << a;
}