#include <iostream>
#include <memory>

#define CARET std::cout<<std::endl;

template <typename T4, typename T5>
void printToConsole (T4 typ, T5 wartosc)
{
    std::cout<< static_cast<T4>(wartosc);
}

struct Print
{
    virtual void print( int ) const = 0;
    virtual ~Print() { }
};

template < class T >
struct PrintT
    : Print
{
    void print( int x ) const override { std::cout << static_cast < T >( x ) << std::endl; }
};


class Object {
   struct ObjectConcept {
       virtual void T_print_() const = 0;
       virtual ~ObjectConcept() {}

   };

   template< typename T > struct ObjectModel : ObjectConcept {
       ObjectModel( const T& t ) : object( t ) {}
       virtual void T_print_() const
       {
           printToConsole(object,object);
       }
       virtual ~ObjectModel() {}
     private:
       T object;
   };

   std::shared_ptr<ObjectConcept> object;

  public:
   template< typename T > Object( const T& obj ) :
      object( new ObjectModel<T>( obj ) ) {}
    void T_print_() const
    {
        object->T_print_();
    }
    friend std::ostream& operator<< (std::ostream& out, const Object& obj)
    {
        obj.T_print_();
        return out;
    }
};
