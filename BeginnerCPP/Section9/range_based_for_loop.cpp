//Range-based for Loop

#include <iostream>
using namespace std;

int main(){

    int scores [] {100,90,97};
    for(int score : scores)
        cout << score << endl;
        
    int scores [] {100,90,97};
    for(auto score : scores)
        cout << score << endl;    
}