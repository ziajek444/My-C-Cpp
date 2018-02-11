/* This program use Escape sequences, to show*/
/* what kind of problem could occurred*/

/*
How to use:
Type the name of file on CMD (or another console),
and next arguments. Arguments which u can type are escape sequences.
U can type as many as u want sequences.
Example:
hello n r b f t v a
hello n b f a ? ' \
Order of parameters is not important,
hello a ' \ f r n
And u can to replicate the same parameters,
hello n r a n r b n r '
Only " u have to type like that:
hello """
!! NOT like that : hello " !!
*/


#include <stdio.h>
int main(int amount,char * content[])
{


/* All escape sequences
\n Represents a newline character (0x0A)
\r Represents a carriage return (0x0D)
\b Represents a backspace (0x08)
\f Represents a form-feed character (0x0C)
\t Represents a horizontal tab (0x09)
\v Represents a vertical tab (0x0B)
\a Inserts a bell (alert) character  (0x07)
\? Inserts a question mark (?) (0x3F)
\" Inserts a double quote (") (0x22)
\' Inserts a single quote (') (0x27)
\\ Inserts a backslash (\) (0x5C)
*/
int i;
char sec;

if(amount<2)
{
    printf("Too few arguments");
    return -1;
}

for(i=0;i<(amount-1);i++)
{
    printf("\n####################################################\n");/*52*/
    content++;
    sec=(char)(*content[0]);
    switch(sec)
    {
    case 'n':
        sec = '\n';
        printf("hex: 0x%X \\n ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",10);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\n text");
    break;
    case 'r':
        sec = '\r';
        printf("hex: 0x%X \\r ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",13);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\r text");
    break;
    case 'b':
        sec = '\b';
        printf("hex: 0x%X \\b ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",8);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\b text");
    break;
    case 'f':
        sec = '\f';
        printf("hex: 0x%X \\f ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",12);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\f text");
    break;
    case 't':
        sec = '\t';
        printf("hex: 0x%X \\t ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",9);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\f text");
    break;
    case 'v':
        sec = '\v';
        printf("hex: 0x%X \\v ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",11);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\v text");
    break;
    case 'a':
        sec = '\a';
        printf("hex: 0x%X \\a ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",7);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\a text");
    break;
    case '?':
        sec = '\?';
        printf("hex: 0x%X \\? ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",63);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\? text");
    break;
    case '\"':
        /* when u want see this context, u have to write """, u can't just write " like with another cases*/
        sec = '\"';
        printf("hex: 0x%X \\\" ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",34);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\" text");
    break;
    case '\'':
        sec = '\'';
        printf("hex: 0x%X \\\' ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",39);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\' text");
    break;
    case '\\':
        /* when u want see this context, u have to write """, u can't just write " like with another cases*/
        sec = '\\';
        printf("hex: 0x%X \\ ",sec);/*first slash is working to next slash, not 'n'*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use from variable: this is%c text",sec);
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use number: this is%c text",92);/*equivalent as number*/
        printf("\n----------------------------------------------------\n");/*52*/
        printf("use into stream: this is\\ text");
    break;
    default:
        printf("\nWrong argument\n");
    break;
    }/*switch*/
}/*for*/

printf("\n####################################################\n");/*52*/
printf("\n");
return 0;
}
