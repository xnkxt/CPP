#include <iostream>
using namespace std;

int main() {
    //try throw catch
    try{
        int age = 10;
        if (age > 18){
            cout <<"access granted!";
        }else{
            throw age;
        }
    }
    catch(int myNum){
        cout << "NO ACCESS" << endl;
        cout << "age is " << myNum;
    }
    return 0;
}