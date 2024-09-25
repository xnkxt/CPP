#include <iostream>

double PI = 3.14;

class Shape{
    
    
    public:
    float PerimeterOfRectangle(float length,float breadth){
        return 2*(length+breadth);
    };
    float PerimeterOfCircle(float radius){
        return 2*PI*radius;
    };
};

int main()
{
    float l,b,r;
    Shape CalcShape;
    std::cout<< "Enter the length of Rectange:";
    std::cin>> l;
    std::cout<< "Enter the breadth of Rectange:";
    std::cin>> b;
    std::cout<<"Perimeter of Rectange is" << CalcShape.PerimeterOfRectangle(l,b);
    std::cout<<"\n";
    std::cout<< "Enter the radius of Circle:";
    std::cin>> r;
    std::cout<<"Circumference of Circle is"<<CalcShape.PerimeterOfCircle(r);
    return 0;
}