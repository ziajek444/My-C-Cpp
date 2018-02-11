#include <iostream>

using namespace std;

class Vector
{
public:

    int x;
    int y;

    Vector():x(0),y(0) {};
    Vector(int x,int y):x(x),y(y) {};
    ~Vector() {};

    // If I using keyword this->, then i have to
    // make overloading inner class or structure
    Vector operator+(const Vector add)
    {
        return Vector( this->x + add.x, this->y + add.y );
    }
    Vector operator+(const int add)
    {
        return Vector( this->x + add, this->y + add );
    }
};

// On this way, I have to not make overloading in class
// or structure, coz i don't use keyword this->
// It is working anyway.
// Doing oveloads after class's brackets have addition advantage,
// I can type 2 parameters, coz in class first parameter is constantly
// connected to function. Owning to the fact, i can do more calculation.
// Example: i can v=1+v and v+v+1, not only v=v+1.
Vector operator+(const int &add,const Vector &v)
{
    return Vector( v.x + add, v.y + add );
}

int main()
{
    Vector v(3,4);
    cout<<v.x<<endl;
    Vector n = 1+v;
    cout<<n.x<<endl;
return 0;
}
