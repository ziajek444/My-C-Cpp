/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;


void WCHAR2Char(wchar_t* wchr)
{
  char tmp;
  int size_wchr=0;
  int zero = 0;
  uint32_t mask = 0;
  int bajt=sizeof(wchar_t);
  char c2w[bajt];

  tmp = (char)wchr[0];
  for( int i=0 ;static_cast<int>(tmp)!=zero; i++ )
  {
    tmp = (char)wchr[i];

    for(int j=0;j<bajt;j++)
    {
        mask = (0xFF<<((bajt-(1+j))*8));
        c2w[j] = ((wchr[i]&mask)>>((bajt-(1+j))*8));
        c2w[j] &= 0xFF;
        if(j==(bajt-1))
        cout<<(char)c2w[j]<<endl;
    }

    size_wchr++;
  }

    //throw "FUK bardzo";
    //return size_wchr;
}

const char * WCHAR2Char4(wchar_t* wchr)
{
  char tmp;
  int size_wchr=0;
  int zero = 0;
  uint32_t mask = 0;
  int bajt=sizeof(wchar_t);
  char c2w[bajt];
  char * nChar = new char; // 'bajt' razy wieksza od wejsciowej

  tmp = (char)wchr[0];
  for( int i=0 ;static_cast<int>(tmp)!=zero; i++ )
  {
    tmp = (char)wchr[i];

    for(int j=0;j<bajt;j++)
    {
        mask = (0xFF<<((bajt-(1+j))*8));
        c2w[j] = ((wchr[i]&mask)>>((bajt-(1+j))*8));
        c2w[j] &= 0xFF;
        nChar[i+j] = (char)c2w[j];
        //cout<<"J: "<<j<<" < "<<(uint32_t)c2w[j]<<" > ";
    }
    //cout<<"| "<<nChar[i]<<"."<<nChar[i+1]<<"."<<nChar[i+2]<<"."<<nChar[i+3]<<" |"<<endl;
    //cout<<"| "<<(int)nChar[i]<<"."<<(int)nChar[i+1]<<" ## "<<(char)nChar[i]<<"."<<(char)nChar[i+1]<<" |"<<endl;
    if(bajt==2)
      {
            cout<<"| "<<(int)nChar[i]<<"."<<(int)nChar[i+1]<<" ## "<<(char)nChar[i]<<"."<<(char)nChar[i+1]<<" |"<<endl;
      }
    else if (bajt==4)
      {
            cout<<"| "<<(int)nChar[i]<<"."<<(int)nChar[i+1]<<"."<<(int)nChar[i+2]<<"."<<(int)nChar[i+3]<<" ## "<<(char)nChar[i]<<"."<<(char)nChar[i+1]<<"."<<(char)nChar[i+2]<<"."<<(char)nChar[i+3]<<" |"<<endl;
      }
    else
        cout<<"O nie nie nie, tak byc nie bedzie #1"<<endl;

    if(size_wchr>1024)
    {
        cout<<"NIE WOLNO TU WCHODZIC, prosze wyjsc!!"<<endl;
        delete [] nChar;
        throw "Too big string";
    }
    size_wchr++;
  }
  cout<<"po wyjsciu z petli"<<endl;
  if(bajt==2)
  {
      for(int o=0;o<size_wchr;o++)
        cout<<"| "<<(int)nChar[o]<<"."<<(int)nChar[o+1]<<" ## "<<(char)nChar[o]<<"."<<(char)nChar[o+1]<<" |"<<endl;
  }
  else if (bajt==4)
  {
      for(int o=0;o<size_wchr;o++)
        cout<<"| "<<(int)nChar[o]<<"."<<(int)nChar[o+1]<<"."<<(int)nChar[o+2]<<"."<<(int)nChar[o+3]<<" ## "<<(char)nChar[o]<<"."<<"."<<(char)nChar[o+1]<<(char)nChar[o+2]<<"."<<(char)nChar[o+3]<<" |"<<endl;
  }
  else
    cout<<"O nie nie nie, tak byc nie bedzie #2"<<endl;

    //delete [] nChar;
    return nChar;
}

int main ()
{
  cout << "Hello World\n\n";

  wchar_t* whr = L"abecadlo\xF0F1";
  //whr += 77;
  //WCHAR2Char(whr);
  const char * WW = WCHAR2Char4(whr);
  //cout<<"bla: "<<(int)WCHAR2Char4(whr)[1]<<endl;
  //cout<<"bla: "<<(int)WCHAR2Char4(whr)[2]<<endl;
  //cout<<"bla: "<<(int)WCHAR2Char4(whr)[3]<<endl;
  //cout<<"bla: "<<(int)WCHAR2Char4(whr)[4]<<endl;



  return 0;
}



