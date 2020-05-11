#ifndef CODE_H
#define CODE_H

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std ; 

//using namespace std ;
class code
{
		public:
			void encrypt(char* filename, char* key) ;
			void decrypt(char* filename) ;
			void Secret_key(char* filename, char* key) ;
};
#endif 

