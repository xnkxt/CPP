#include <iostream>
#include <string>

using namespace std;

int main() {
  int num1;
  int num2;
  string decision;
  
  
  cout << "Enter number one:";
  cin >> num1;
  
  cout << "Enter second number:";
  cin >> num2;
  
  cout << "Type add for addtion\n sub for substraction\n div for division\n mul for multiplication\n";
  cin >> decision;

  if (decision == "add"){
    cout << num1+num2;
  } else if (decision == "sub") {
    cout << num1-num2;
  }else if (decision == "div") {
    cout << num1/num2;
  }else if (decision == "mul") {
    cout << num1*num2;
  }else {
    cout << "_____WRONG INPUT_____";
  }
  return 0;
}