#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//Sizeof = 8B

class DYNAMIC
{
    public:
        void *pointer;
        char type; // 0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,

        explicit DYNAMIC()
        {
            cout<<"dynamic start"<<endl;
            type = 0;
        }
        ~DYNAMIC()
        {
            ClearMem();
            cout<<"dynamic terminated"<<endl;
        }
        /*DYNAMIC(const DYNAMIC& a) {
            pointer = new short;
            *pointer = *a.pointer;
            test = a.test;
        }*/

        operator char()
        {
            return this->type==1 ? *((char*)pointer) : '\0';
        }
        operator short()
        {
            return this->type==2 ? *((short*)pointer) : 0;
        }
        operator int()
        {
            return this->type==3 ? *((int*)pointer) : 0;
        }
        operator float()
        {
            return this->type==4 ? *((float*)pointer) : 0.0;
        }
        operator double()
        {
            return this->type==5 ? *((double*)pointer) : 0.0;
        }
        operator string()
        {
            return this->type==6 ? *((string*)pointer) : "\0";
        }

        // template
        /*template <class T>
        DYNAMIC& operator=(const T& arg1) //for auto variable
        {
            this->ClearMem();
            this->type=99;
            pointer = new T;
            *((T*)pointer) =  arg1;
            cout<<"#a#T#"<<endl;
            return *this;
        }*/

        // CHAR
        DYNAMIC& operator=(const char& arg1) //for auto variable
        {
            this->ClearMem();
            this->type=1;
            pointer = new char;
            *((char*)pointer) =  arg1;
            cout<<"#a#char#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const char&& arg2) //for rvalue
        {
            ClearMem();
            this->type=1;
            pointer = new char;
            *((char*)pointer) =  arg2;
            cout<<"#r#char#"<<endl;
            return *this;
        }
        // SHORT
        DYNAMIC& operator=(const short& arg1) //for auto variable
        {
            ClearMem();
            this->type=2;
            pointer = new short;
            *((short*)pointer) =  arg1;
            cout<<"#a#short#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const short&& arg2) //for rvalue
        {
            ClearMem();
            this->type=2;
            pointer = new short;
            *((short*)pointer) =  arg2;
            cout<<"#r#short#"<<endl;
            return *this;
        }
        // INT
        DYNAMIC& operator=(const int& arg1) //for auto variable
        {
            ClearMem();
            this->type=3;
            pointer = new int;
            *((int*)pointer) =  arg1;
            cout<<"#a#int#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const int&& arg2) //for rvalue
        {
            ClearMem();
            this->type=3;
            pointer = new int;
            *((int*)pointer) =  arg2;
            cout<<"#r#int#"<<endl;
            return *this;
        }
        DYNAMIC& operator+(const int& right)
        {
            *((int*)pointer)+=right;
            return *this;
        }
        friend DYNAMIC& operator+(const int& left, DYNAMIC& object);
        // FLOAT
        DYNAMIC& operator=(const float& arg1) //for auto variable
        {
            ClearMem();
            this->type=4;
            pointer = new float;
            *((float*)pointer) =  arg1;
            cout<<"#a#float#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const float&& arg2) //for rvalue
        {
            ClearMem();
            this->type=4;
            pointer = new float;
            *((float*)pointer) =  arg2;
            cout<<"#r#float#"<<endl;
            return *this;
        }
        // DOUBLE
        DYNAMIC& operator=(const double& arg1) //for auto variable
        {
            ClearMem();
            this->type=5;
            pointer = new double;
            *((double*)pointer) =  arg1;
            cout<<"#a#double#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const double&& arg2) //for rvalue
        {
            ClearMem();
            this->type=5;
            pointer = new double;
            *((double*)pointer) =  arg2;
            cout<<"#r#double#"<<endl;
            return *this;
        }
        // STRING
        DYNAMIC& operator=(const string& arg1) //for auto variable
        {
            ClearMem();
            this->type=6;
            pointer = new string;
            *((string*)pointer) =  arg1;
            cout<<"#a#string#"<<endl;
            return *this;
        }
        DYNAMIC& operator=(const string&& arg2) //for rvalue
        {
            ClearMem();
            this->type=6;
            pointer = new string;
            *((string*)pointer) =  arg2;
            cout<<"#r#string#"<<endl;
            return *this;
        }

        friend ostream& operator<<(ostream& out, DYNAMIC& object);
        friend istream& operator>>(istream& in, DYNAMIC& object);

        void PRINT()
        {
            switch(this->type) //0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,
            {
                case 0:

                    break;
                case 1:
                    cout<<"get: "<<*((char*)pointer)<<endl;
                    break;
                case 2:
                    cout<<"get: "<<*((short*)pointer)<<endl;
                    break;
                case 3:
                    cout<<"get: "<<*((int*)pointer)<<endl;
                    break;
                case 4:
                    cout<<"get: "<<*((float*)pointer)<<endl;
                    break;
                case 5:
                    cout<<"get: "<<*((double*)pointer)<<endl;
                    break;
                case 6:
                    cout<<"get: "<<*((string*)pointer)<<endl;
                    break;
                default:
                    break;
            }
        }

        void ClearMem()
        {
            switch(this->type) //0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,
            {
                case 0:

                    break;
                case 1:
                    delete (char*)pointer;
                    break;
                case 2:
                    delete (short*)pointer;
                    break;
                case 3:
                    delete (int*)pointer;
                    break;
                case 4:
                    delete (float*)pointer;
                    break;
                case 5:
                    delete (double*)pointer;
                    break;
                case 6:
                    delete (string*)pointer;
                    break;
                default:
                    delete pointer;
                    break;
            }
        }

};

ostream& operator<<(ostream& out, DYNAMIC& object)
{
    switch(object.type)
    {
    case 0:
        out << "\0";
        break;
    case 1:
        out <<*((char*)object.pointer);
        break;
    case 2:
        out <<*((short*)object.pointer);
        break;
    case 3:
        out <<*((int*)object.pointer);
        break;
    case 4:
        out <<*((float*)object.pointer);
        break;
    case 5:
        out <<*((double*)object.pointer);
        break;
    case 6:
        out <<*((string*)object.pointer);
        break;
    default:
        out <<object.pointer;
        break;
    }
return out;
}

istream& operator>>(istream& in, DYNAMIC& object)
{
    //Basically treat like string
// 43 +  45 -
// 44 ,  46 .
// 48-57 -> 0-9
 bool notInt = false;
 bool notDouble = false;
 int i=0;
 string tmp = "";
 in >> tmp;
 if(!tmp.empty())
 {
    if (tmp.length()==1)
    {
        if (object.type == 0 || object.type == 1) { object = static_cast<char>(tmp[0]); }
        else if (object.type == 2 && (tmp[0]>='0' && tmp[0]<='9')) { object = static_cast<short>(static_cast<short>(tmp[0])-48); }
        else if (object.type == 3 && (tmp[0]>='0' && tmp[0]<='9')) { object = static_cast<int>(static_cast<int>(tmp[0])-48); }
        else object = static_cast<string>(tmp);
    }
    else
    {
        if(object.type != 0 && object.type != 1 && object.type != 6) //It is number, not text try to find number
        {
            if (tmp[0]=='-' || tmp[0]=='+') i++;

            for(i;i<tmp.length();i++)
            {
                if ((tmp[i]>='0' && tmp[i]<='9') || tmp[i]==',' || tmp[i]=='.')
                {
                    if ((tmp[i]==',' || tmp[i]=='.') && notInt) { notDouble = true; break; }
                    if ((tmp[i]==',' || tmp[i]=='.') && !notInt) { notInt = true; }
                }
                else
                {
                    notDouble = notInt = true;
                    break;
                }

            }

            if (!notInt)
            {
                object = atoi(tmp.c_str());
            }
            else if (!notDouble)
            {
                if(tmp.find(',')) tmp = tmp.substr(0,tmp.find(',')) + '.' + tmp.substr(tmp.find(',')+1);
                object = atof(tmp.c_str());
            }
            else
            {
                object = static_cast<string>(tmp);
            }
        }
        else
        {
            object = static_cast<string>(tmp);
        }
    }

 }
 return in;
}

DYNAMIC& operator+(const int& left, DYNAMIC& object)
{
    object = *((int*)object.pointer) + left;
    return object;
}

int main() {
    /*DYNAMIC d;
    d = 4;
    d.PRINT();
    int i = 8;
    d=i;
    d.PRINT();
    double dbl = 999.4567;
    d=dbl;
    d.PRINT();
    char c = 'q';
    d=c;
    d.PRINT();
    string str = "text";
    d=str;
    d.PRINT();


    DYNAMIC d2;
    d2 = 'H';
    int INT = d2;
    cout<<"1# int: "<<INT<<" for non int schould be 0"<<endl;


    d2 = 444;
    INT = d2;
    cout<<"2# int: "<<INT<<" for int type schould be correct value"<<endl;


    cout<<"sizeof dynamic: "<<sizeof(d)<<endl;*/
    DYNAMIC dd;
    int a = 2;
    dd = a;
    cout<<3+dd<<endl;


    return 0;
}


