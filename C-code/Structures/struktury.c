#include <stdio.h>

/* Structure contain many variables and
 existed finity amount structures like that.
 I think, i can use it to grouped my variables at more understandable
 parts.
 Example:
 struct {
    int x;
    int y;
    int z;
} positions;

 struct {
    int isOpen;
    int isAvailable;
    int occurred;
} flags;

 struct {
    char * unexpectedCloseWindow;
    char * error;
    char * splatBug;
} warnings;

 */


struct {
    int intVar01;
    int intVar02;
    int intVar03;
    char * strVar;
    char charVar;
} unnamedStructure, secondUnnameStructure;

/* The similar case is make structure with structure's name and
immediately initiating the object. The difference is, u can create another
objects of structure at the program.*/

struct MyStructure {
    int intVar01;
    int intVar02;
    int intVar03;
    char * strVar;
    char charVar;
} MyObject1; /* The object of MyStructure */

/* Use typedef to create yourself keyword. It allow u to declare new object od structure without struct keyword */
typedef struct string {

    char * STR;

} string; /* My own keyword at ref to avoid structure */

/* C doesn't use constructors in structures. This is the first difference between c and c++.
 Every fld is public, u can define structure like a vector of variables */

int main(int amount,char * content[])
{
    /* In reference to ISO C90 every variable have to be declared at the top of main(),
    and comments making by // are not allowed */

    /* 3 print */
    string myString;
    /* 2 print */
    struct MyStructure MyObject2 ;
    MyObject2.strVar = "Am second";
    MyObject1.strVar = "Am first";
    /* 1 print */
    secondUnnameStructure.strVar = "almost like Singleton :D";
    unnamedStructure.intVar01 = 1;

    myString.STR = "almost like a real string from c++";

    /* 1 */printf("Unnamed structures: %d %s\n",unnamedStructure.intVar01,secondUnnameStructure.strVar);
    /* 2 */printf("My Structures: %s %s\n",MyObject2.strVar,MyObject1.strVar);
    /* 3 */printf("My string: %s\n", myString.STR);

    return 0;
}
