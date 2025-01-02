#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> test (10, 5);
    for(int i=0;i<test.size();i++){
        cout << i <<" " << test[i] << endl; 
    }
    return 0;
}