#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vasd{};
    vasd.push_back(1);
    vasd.push_back(2);
    for (size_t i=0; i<vasd.size();i++){
        cout << vasd[i];
    }

    return 0;
}