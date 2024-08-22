#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter year: " << endl;
    cin >> year;
    
    if (year%4==0) {
        cout<<"It is a leap year";
    }else{
        cout<<"Not a leap year";
    }
    return 0;
}