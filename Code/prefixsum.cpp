#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};
    int prefix[5] = {1};
    prefix[0] = arr[0];

    for(int i=1;i<5;i++){
        prefix[i] = arr[i] + prefix[i-1];
    }
    for(int i=0;i<5;i++){
        cout << prefix[i] << " ";
    }
    return 0;
}