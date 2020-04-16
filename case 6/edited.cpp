//#include "copyconst.h"
#include<iostream>
#include<string.h>
using namespace std;
#include "copyconst.h"

	CopyConstructor::CopyConstructor(const char *str,int p)
    {
        s_copy = new char[strlen(str)+1]; //Dynamic memory allocation
        strcpy(s_copy, str);
		ptr=new int;
		*ptr=p;
	
    }

 	CopyConstructor::CopyConstructor(CopyConstructor &s,CopyConstructor &p)
    {
		cout<<"deepcopy"<<endl;
		s_copy=new char[strlen(s.s_copy)+1];
        strcpy(s_copy, s.s_copy);
		ptr=new int;
		*ptr=p.getx();
    }

	int CopyConstructor:: getx()
	{
		return *ptr;
	}
   
    /* concatenate method */
    void CopyConstructor:: concatenate(const char *str,int m)
    {
        strcpy(s_copy, str); //Concatenating two strings
	*ptr=m;
    }
   
    /* copy constructor */
   	CopyConstructor::~CopyConstructor ()
	{
   	
	} 
   
    void CopyConstructor:: display()
    {
        cout<<s_copy<<endl;
	cout<<*ptr<<endl;
    }

/* main function */
int main()
{
    CopyConstructor c1("Copy",9);
    CopyConstructor c2=c1; //Copy constructor
    c1.display();
    c2.display();
    c1.concatenate("Constructor",8);    //c1 is invoking concatenate()
    c1.display();
    c2.display();
    return 0;
}
