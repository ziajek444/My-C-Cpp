#include <iostream>
#include <math.h>

using namespace std;

/*
important is to make init list in same order as definition.
ex:
private:
    int x1;
    int x2;
    char y1;
    char y2;
public:
    constructor(int i1, char c1, int i2): x1(i1),x2(i2),y1(c1),y2(c1)
    { };

Below if not correct
constructor(int i1, char c1, int i2): x2(i2),y1(c1),x1(i1),y2(c1)
    { };
constructor(int i1, char c1, int i2): y2(c1),y1(c1),x2(i2),x1(i1)
    { };
*/

class Rint //range integer
{
private:
    int min_val;
    int max_val;
    int val;
    int range;
public:
    ~Rint() {};
    Rint():min_val(0),max_val((int)pow(2,sizeof(int)*7)-1),val(0)
    {
        range = (max_val+1)-min_val;
    };

    Rint(int x1):min_val(0),max_val(x1),val(0)
    {
        if(max_val<=0)
        {
            cout<<"wrong first parameter in Rint(int), max value must be higher than 0"<<endl;
            throw this;
        }
        range = (max_val+1)-min_val;
    }
    Rint(int x1,int x2):min_val(x1),max_val(x2),val(0)
    {
        if(max_val<=min_val)
        {
            cout<<"wrong parameters in Rint(int,int), max value must be higher than min value"<<endl;
            throw this;
        }
        range = (max_val+1)-min_val;
    }
    Rint(int x1,int x2,int x3):min_val(x1),max_val(x2),val(x3)
    {
        if(max_val<=min_val) { cout<<"wrong second parameter in Rint(int,int,int), max value must be higher than min value"<<endl; throw this; }
        else if(val<min_val) { cout<<"wrong third parameter in Rint(int,int,int), main value must be higher than min value"<<endl; throw this; }
        else if(val>max_val) { cout<<"wrong third parameter in Rint(int,int,int), main value must be lower than max value"<<endl; throw this; }
        range = (max_val+1)-min_val;
    }
    // If I using keyword this->, then i have to
    // make overloading inner class or structure
    friend Rint operator+(const int &add,const Rint &v);
    friend Rint operator-(const int &sub,const Rint &v);
    friend ostream& operator<<(ostream& out,Rint &v);
    Rint operator+(const int add)
    {
        int temp = add;
        while(temp>=this->range) { temp-=this->range; }
        if((this->val + temp)>this->max_val) { this->val = (this->min_val+temp)-1; }
        else this->val += temp;

        return *this;
    }
    Rint operator=(const int &newcopy)
    {
        this->val = newcopy;
        return *this;
    }

};

// On this way, I have to not make overloading in class
// or structure, coz i don't use keyword this->
// It is working anyway.
// Doing oveloads after class's brackets have addition advantage,
// I can type 2 parameters, coz in class first parameter is constantly
// connected to function. Owning to the fact, i can do more calculation.
// Example: i can v=1+v and v=v+1, not only v=v+1.
Rint operator+(const int &add,const Rint &v)
{
    Rint V(v.min_val,v.max_val,v.val);
    int temp = add;

    while(temp>=V.range) { temp-=V.range; }
    if((V.val + temp)>V.max_val) { V.val = (V.min_val+temp)-1; }
    else V.val += temp;

    return V;
}
Rint operator-(const int &sub,const Rint &v)
{
    Rint V(v.min_val,v.max_val,v.val-sub);
    return V;
}
ostream& operator<<(ostream& out,Rint &v)
{
    out <<v.val;
    return out;
}

int main()
{
    Rint v;
    for(int i=0;i<12;i++) { v = v+10; cout<<v<<endl; v = 10+v; }
    v = 255+v;
    Rint v2=50;
    //nie dzia³a inicjalizacja (równoczesna deklaracja i przypisanie wartoœci)


    cout<<v2<<endl;
return 0;
}
