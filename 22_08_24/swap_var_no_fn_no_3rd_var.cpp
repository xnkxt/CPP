/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int num1,num2;
    
    cout<<"Enter Number one:";
    cin>>num1;
    cout<<"Enter Number two:";
    cin>>num2;
    
    num1 = num1+num2;
    num2 = num1-num2;
    num1 = num1-num2;
    
    cout<<"Number 1 is now: " << num1 << endl;
    cout<<"Number 2 is now: " << num2 << endl;

    return 0;
}