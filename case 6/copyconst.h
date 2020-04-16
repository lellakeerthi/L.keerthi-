#ifndef COPY_CONSTRUCTOR_H
#define COPY_CONSTRUCTOR_H

#include<string.h>
using namespace std ;
class CopyConstructor
{
	char *s_Copy;
    int *ptr;
public:
	CopyConstructor(const char *str,int Num) ;
	CopyConstructor(CopyConstructor &s,CopyConstructor &p) ;
		int getx() ;
		void concat(const char *str,int No) ;
		~CopyConstructor () ;
		 void display() ;
		 
	    
};
#endif 

