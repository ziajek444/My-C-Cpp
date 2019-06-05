//#include "pch.h"
#include <iostream>
#include <typeinfo>       // operator typeid
#include <typeindex>      // std::type_index
#include <string>
#include <string.h>
#include <stdint.h>
#include "AbstractClass.h"
#include <memory>


#define TYPE(x) typeid(x).name()

#define __POINTERTYPE 1

template <class Type>
void print(const Type p);
template <class Type>
void println(const Type p);

//------------------------------------------------- dynamic

template <typename T1, typename T2>
void printToConsole(T1 typ, T2 wartosc)
{
	std::cout << static_cast<T1>(wartosc);
}
template <typename T1, typename T2>
T1 kastowanie(T1 typ, T2 wartosc)
{
	return static_cast<T1>(wartosc);
}

class dynamic
{

#pragma region dynamic type erasure
	private:
		struct ObjectConcept {
			public:
				virtual void PrintFromDynmic() const = 0;
				virtual void SetObjectValue(int * adres) const = 0;
				virtual ~ObjectConcept() {}
		};

#if __POINTERTYPE == 1
		template< class T3 > 
		struct ObjectModel : ObjectConcept {
			public:
				ObjectModel(const T3& t)  {
					//int size = sizeof(t) / sizeof(T3);
					//object = new T3[size];
					object = const_cast<T3*>(&t);
					IsNeedToDeallocate = false;
				}
				ObjectModel(const T3&& t)  {
					object = new T3[1];
					object[0] = t;
					IsNeedToDeallocate = true;
				}
				virtual void PrintFromDynmic() const
				{
					printToConsole(*object, *object);
				}
				virtual void SetObjectValue(int * adres) const {
					// to do
				}
				virtual ~ObjectModel() {
					if(IsNeedToDeallocate)
						delete[] object;
				}
			public:
				T3 * object;
			private:
				int IsNeedToDeallocate;
		};
#else
		template< class T3 >
		struct ObjectModel : ObjectConcept {
		public:
			ObjectModel(const T3& t) {
				object = t;
			}
			ObjectModel(const T3&& t) {
				object = t;
			}
			virtual void PrintFromDynmic() const
			{
				printToConsole(object, object);
			}
			virtual ~ObjectModel() {}
		private:
			T3 object;
		};
#endif
		
#pragma endregion

#pragma region ctors
public:
	dynamic() : self_ID(++this->ID), data_type(typeid(void))
	{
		initialized = false;
		var_size = type_size = 0;
	}
	dynamic(dynamic& dynamic_in) : self_ID(++this->ID), data_type(typeid(void))
	{
		std::cout << "dyn ass\r\n";
		DYNAMIC = dynamic_in.getObject();

		initialized = dynamic_in.IsInitialized();
		var_size    = dynamic_in.getVarSize();
		type_size   = dynamic_in.getTypeSize();
	}
	template <typename T4>
	dynamic(const T4& obj_in) : self_ID(++this->ID), data_type(typeid(T4)), DYNAMIC(new ObjectModel<T4>(obj_in))
	{
		initialized = true;
		var_size    = sizeof(obj_in);
		type_size   = sizeof(T4);
	}
	template <typename T5>
	dynamic(const T5&& obj_in_r) : self_ID(++this->ID), data_type(typeid(T5)), DYNAMIC(new ObjectModel<T5>(obj_in_r))
	{
		initialized = true;
		var_size    = sizeof(obj_in_r);
		type_size   = sizeof(T5);
	}

#pragma endregion

#pragma region Self functions
	public:
		const int getID() const    { return this->self_ID;     }
		bool IsInitialized() const { return this->initialized; }
		int getVarSize() const     { return this->var_size;    }
		int getTypeSize() const    { return this->type_size;   }
		std::shared_ptr<ObjectConcept> getObject() const
		                           { return this->DYNAMIC;     } 
#pragma endregion

#pragma region override functions
	private:
		void PrintFromDynmic() const
		{
			(this->DYNAMIC)->PrintFromDynmic();
		}
#pragma endregion

#pragma region assigns
	public:
		dynamic & operator= (const dynamic& dynamic_in)
		{
			this->DYNAMIC = dynamic_in.getObject();

			initialized = dynamic_in.IsInitialized();
			var_size = dynamic_in.getVarSize();
			type_size = dynamic_in.getTypeSize();

			return *this;
		}
		template <class Temp>
		dynamic & operator= (const Temp & x) 
		{
			data_type = typeid(Temp);
			DYNAMIC = std::make_shared<ObjectModel<Temp>>(x); //new ObjectModel<Temp>(x);
			initialized = true;
			var_size = sizeof(x);
			type_size = sizeof(Temp);
			return *this;
		}
		template <class Temp>
		dynamic & operator =(const Temp && x) 
		{
			data_type = typeid(Temp);
			DYNAMIC = std::make_shared<ObjectModel<Temp>>(x); //new ObjectModel<Temp>(x);
			initialized = true;
			var_size = sizeof(x);
			type_size = sizeof(Temp);
			return *this;
		}
#pragma endregion

#pragma region OSTREAM !!
	// There is the real powerfull of my work. No one can do that ! (not even ::any)
	public:
		friend std::ostream & operator<< (std::ostream & out, const dynamic & am) {
			am.PrintFromDynmic();
			return out;
		}
#pragma endregion

#pragma region dodawanie
		// There is the real powerfull of my work. No one can do that ! (not even ::any)
	public:
		template <class T>
		T operator+ (const T & value) const {
			//tutaj chce dodac object.. trail->
			//(this->DYNAMIC)->PrintFromDynmic(); (ObjectModel) ->
			//printToConsole(*object, *object); (fun zewnetrzna)
			//return this->DYNAMIC;
			//dynamic_cast<ObjectModel&>(DYNAMIC);
			int k = 9;
			//ObjectModel * p = new ObjectModel();
			return 0;
			// TODO
		}
#pragma endregion

#pragma region Dtor
	public:
		virtual ~dynamic() { }
#pragma endregion

#pragma region variables
private:
	static int ID;
	const int self_ID;
	std::shared_ptr<ObjectConcept> DYNAMIC;
	bool initialized;
	std::type_index data_type;
	int var_size;
	int type_size;
	
#pragma endregion

};

//--------------obiekt
class klasa
{
	
public:
	klasa() : kalosz(7)
	{

	}
	int kalosz;

	void SetKalosz(int newValue)
	{
		kalosz = newValue;
	}

	int GetKalosz() { return kalosz; }

public:
	friend std::ostream & operator<< (std::ostream & out, const klasa & am) {
		out << "kalosz: " << am.kalosz;
		return out;
	}


};

//------------------------------------------------- main

int main()
{
	
	dynamic d = 4;
	dynamic dyn = d;
	std::cout << "=> 4_/4_ \r\n";
	std::cout << d << std::endl;
	std::cout << dyn << std::endl;
	d = 44;
	std::cout << "=> 44/4_ \r\n";
	std::cout << d << std::endl;
	std::cout << dyn << std::endl;
	dyn = d;
	std::cout << "=> 44/44 \r\n";
	std::cout << d << std::endl;
	std::cout << dyn << std::endl;

	//d = (std::string)"stringers"; // ok
	//d = (const char *)"stringers"; // ok
	d = "stringers";
	std::cout <<"\r\n"<< d << std::endl;

	std::string s = "slowo";
	d = s;
	std::cout << "\r\n" << d << std::endl;

	d = 5;
	std::cout << "\r\n" << d << std::endl;
	int liczba = 3;
	std::cout << "\r\n" << d + liczba << std::endl;


	std::cin.get();

	return 0;

}

//------------------------------------------------- body

int dynamic::ID = 0;

template <class Type>
void print(const Type p)
{
	std::cout << p;
}

template <class Type>
void println(const Type p)
{
	std::cout << p << std::endl;
}
