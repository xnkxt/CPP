//Output
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 

#include <iostream>
using namespace std;

int main()
{
    
    int c = 1; 
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j <= i; j++ ){
            cout << (c++) << " ";
        }
        cout << endl;
    }
    return 0;
}