#include <iostream>
#include <string>

using namespace std;

int main() {
    int checknum;
    
    cout << "Enter the number to check if its prime or not:";
    cin >> checknum;
    
    if (checknum == 0 || checknum == 1) {
        cout << "Not a prime a prime number";
    }else if(checknum % 2 == 0){
        cout << "Not a prime a prime number";
    }else {
        cout << "It is a prime number";
    }
    return 0;
}