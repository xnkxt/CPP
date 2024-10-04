#include <iostream>
#include <string>
using namespace std;

int main(){

    string name;
    cout << "Enter Name: ";
    cin >> name;

    int nums_of_unit=0;
    cout << "Enter Units you want to buy: ";
    cin >> nums_of_unit;

    int cost = 0;

    if (nums_of_unit<=100){
        cost = nums_of_unit * 0.60;
    }else if (nums_of_unit<=300){
        cost = (100*0.60)+(nums_of_unit-100*0.80);
    }else{
        cost = (100*0.60 + 200*0.80) + (nums_of_unit-(300 * 0.90));
    }
    if (cost < 50){
        cost = 50;
    }
    if (cost >300) {
        cost = cost+cost*0.15;
    }
    cout << "Name of the User: " << name << endl;
    cout << "Cost in Rupees: "<< cost;
    return 0;
}