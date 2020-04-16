#include<iostream>
#include<string.h>

using namespace std;

#include "copyconst.h"
// class is in copyconst.h 
 
	CopyConstructor::CopyConstructor(const char *str,int Num)
    {
        s_Copy = new char[strlen(str)+1]; 
        strcpy(s_Copy, str);
		ptr=new int;
		*ptr=Num;
    }

 	CopyConstructor::CopyConstructor(CopyConstructor &s, CopyConstructor &p )
    {
		s_Copy=new char[strlen(s.s_Copy)+1];
        strcpy(s_Copy, s.s_Copy);
		ptr=new int;
		*ptr=p.getx();
    }

	int CopyConstructor:: getx()
	{
		return *ptr;
	}
   
    void CopyConstructor::concatenate(const char *str,int No)
    {
        strcpy(s_Copy, str); 
		*ptr=No ;
    }
   
   	CopyConstructor::~CopyConstructor ()
	{
   	
	} 
   
    void CopyConstructor:: display()
    {
        cout<<s_Copy<<endl;
		cout<<*ptr<<endl;
    }

int main(int argc,char *argv[])  
{
	if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
  
		cout << " usage of " << argv[0] << endl;            
		
	}
	else 
	{
    CopyConstructor c1("Copy",9);
    //Copy constructor
	CopyConstructor c2=c1; 
    c1.display();
    c2.display();
    //c1 is invoking concatenate()
	c1.concatenate("Constructor",8);    
    c1.display();
    c2.display();
    return 0;
	}
}
