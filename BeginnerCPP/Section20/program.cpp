#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> v {4,2,1,3,5,6};

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto elem: v){
        cout << elem;
    }

    return 0;
}