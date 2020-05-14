#ifndef CODE_H
#define CODE_H

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std ; 

//using namespace std ;
class code
{
	//private members
	private:
		char alpha ;
	//public members
	public:
		code() ;	
		void encrypt(char* filename, char* key) ;
		void decrypt(char* filename, char* key) ;

};
#endif 

