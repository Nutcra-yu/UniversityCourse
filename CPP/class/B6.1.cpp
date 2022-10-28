#include<iostream>
#include"B5.4.cpp"
using namespace std;

class Point
{
private:
    float x, y;

public:
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    virtual float Area() = 0;
};

class Circle : public Point
{
private:
    float radius;

public:
    Circle(float radius, float x, float y) : Point(x, y)
    {
        this->radius = radius;
    }
    float Area()
    {
        return 3.14*(radius/2)*(radius/2);
    }
};

class Rectangle : public Point
{
private:
    float sidea, sideb;

public:
    Rectangle(float sidea, float sideb, float x, float y) : Point(x, y)
    {
        this->sidea = sidea;
        this->sideb = sideb;
    }
    float Area()
    {
        return sidea*sideb; 
    }
};

int main()
{
    Circle circle(10,1,1);
    Rectangle rectangle(10,8,0,0);

    cout<<"area of circle="<<circle.Area()<<endl;
    cout<<"area of rectangle="<<rectangle.Area()<<endl;

    system("pause");
}