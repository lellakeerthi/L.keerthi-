/*Description: to encrypt and decrypt the a file
Filename:encode.cpp
Author:l.keerthi
date:09-5-2020
*/	
#include <iostream>
#include<string.h>
#include"encode.h"

using namespace std ;

int main(int argc,char *argv[])  
{
	int find ;
	encode encodeObj ;
	// checking arguments to display -h
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		cout << " usage of"<< argv[0] <<endl;           
		cout << "-f filename -e encryption / -d decryption -k key " << endl ;	
	}
		
	else if(argc>2) 
	{
		char* filename; 
		char* key;
		
		if((strcmp(argv[1],"-e")==0) || (strcmp(argv[1],"-d")==0))
		{
		
			//for finding -f & -k
			for (int indx = 0; indx < argc; indx++)
			{
				if (strcmp(argv[indx], "-f") == 0)
					filename = argv[indx + 1];
				else  if (strcmp(argv[indx], "-k") == 0)
					key = argv[indx + 1];
			}
			//encryption
			if (strcmp(argv[1], "-e") == 0)
			{
				find = encodeObj.encrypt(filename, key);
				if (find == 1)
					cout << "encryption executed" << endl;
				else
					cout << "encryption not executed" << endl;
			}
			//decryption
			else if (strcmp(argv[1], "-d") == 0)
			{
				find = encodeObj.decrypt(filename, key);
				if (find == 1)
					cout << "decryption executed" << endl;
				else
					cout << "decryption not executed" << endl;
			}
		}
		else
		{
			cout<<"invalid arguments" ;
		}

			
	}
	else
	{
		cout<< " use -h for usage " ;
	}	
}
